<h2 align=center>Linux 编译安装 openssl库

</h2>



如果是不需要特定版本的openssl库的安装非常简单。直接`sudo apt install opensll`即可。而且像Ubuntu这种应该是自带了openssl库的。运行`openssl version -a`查看版本。

![p0](F:\Code\Code\openssl\openssl_ubuntu_dufault_version.png)

当这个默认版本不满足我们的使用要求时，我们需要自己编译安装需要的版本。方法如下。



#### 1、下载openssl源码

---

openssl官网链接：https://www.openssl.org/

找到需要下载的版本：https://www.openssl.org/source/old/1.0.0/

![image-20200702215856641](F:\Code\Code\openssl\download_of_opensll_link.png)

这里我需要下载的版本是`openssl-1.0.0c`。把下载压缩包放到一个你能找得到的路径下，然后进行解压。

#### 2、编译安装

---

* **config配置**

  配置编译参数。这里的一些参数说明可以在**github**的**openssl**上找到https://github.com/openssl/openssl。

  参数列得很全，但是使用说明并不太详细。建议直接百度搜。github上的虽然不详细，但是都是对的，百度搜出来的一些参数使用是错误的。这里我只编译Linux共享库，所以只加了一个`shared`参数。安装路径为默认的`/usr/local/ssl`，不进行设置。

  我使用的是wsl进行编译的。（后面我还会用交叉工具链进行再次编译，这个使用wsl不再那么好使了，貌似是因为wsl不支持32位程序。然后网上也有解决方法，简单尝试后仍然没办法编译。后面转虚拟机了)

  ```shell
  $ ./config shared
  ```

  ![p1](F:\Code\Code\openssl\config_outprint.png)

  出现`Configure for linux-x86_64`应该就是配置成功了。



* **make编译**

  配置好编译选项后，运行make，一直等着就好了。应该是没有什么问题的。

  ```shell
  $ make
  ```

  ![p2](F:\Code\Code\openssl\openssl_make_success.png)

  

* **make test测试**

  make编译成功后，可以进行make test。我这里测试存在两个错误，查资料说是bug，然后就没管了。

  ![p3](F:\Code\Code\openssl\make_test_error.png)

  

* **make install安装**

  这里需要用root权限，加sudo进行安装。否则会报错。

  ```shell
  # sudo make install
  ```

  ![p4](F:\Code\Code\openssl\make_install_error.png)

  运行仍然存在错误。搜了一下，删除一个相关文件就好了。

  ```shell
  # sudo mv /usr/bin/pod2man /usr/bin/pod2man_cp
  ```

  ![p5](F:\Code\Code\openssl\make_install_success.png)

  安装完成。这里还没有把库加到系统默认路径下，所以gcc 是没有办法直接使用的。如果要使用的话，通过-L来指定库**libssl.so.1.0.0**和**libcrypto.so.1.0.0**的路径。

  ![p6](F:\Code\Code\openssl\openssl_dir.png)

  

#### 3、创建软链接

![p7](F:\Code\Code\openssl\create_soft_link_openssl.png)

![p8](F:\Code\Code\openssl\version_check.png)

此时版本已经切换成我们自己编译安装的版本了。如果要切回去的话，将`/usr/bin/openssl_cp`备份恢复即可。



#### 4、gcc使用openssl库

```shell
# sudo vim /etc/ld.so.conf
```

将`/usr/local/openssl/lib`加到最后面的新行。然后执行

```shell
# sudo ldconfig
```

这时在链接选项后添加`LDFLAGS = -lssl -lcrypto`即可将openssl库链接进来。



#### 5、交叉编译openssl

openssl支持交叉编译配置。在github的教程中有讲到如何使用`--cross-compile-prefix=`。

我是通过在虚拟机ubuntu18.04上进行交叉编译的。工具链是**arm-himix100-linux**。

![p9](F:\Code\Code\openssl\cross_compile_github.png)

由于是交叉编译，所以需要设置交叉编译配置项，并且不要安装在默认位置了。

```shell
$ ./config no-asm shared --prefix=/home/river/Project/IPC/cross_compiling --cross-compile-prefix=arm-himix100-linux-
$ make
$ sed -i "s/-m64//g" Makefile
$ make
# sudo make install
```

过程中会报一个关于`-m64`的错误。直接删除Makefile中的`-m64`。

no-asm: 不适用汇编代码。

--prefix: 为openssl安装路径。

![p10](F:\Code\Code\openssl\ubuntu_cross_compile_success.png)

编译安装成功。

![p11](F:\Code\Code\openssl\ubuntu_openssl_dir.png)