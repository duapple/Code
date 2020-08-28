<h2 align=center>ubuntu 安装 qv2ray教程</h2>

#### 1. 安装qv2ray

先安装GUI程序。这里我是在github上找的qv2ray项目的发布链接：https://github.com/Qv2ray/Qv2ray/releases。

教程链接是：https://qv2ray.github.io/getting-started/。

教程里面只有arch系列的安装方法，从aur直接安装，相当的方便。对于debian系的来说，就比较麻烦了。我先下载了.deb格式的包，但是`sudo dpkg -i qv2ray*.deb`时，因为依赖问题而安装不上。通过`sudo apt install -f `依旧没有解决掉这个依赖问题。通过ubuntu的应用商店也找到了qv2ray，也是安装不上。

最终通过google找到了安装方法，非常的简单，感觉是通过命令行的应用商店进行安装的。

至于从github上下东西和google，过程太艰辛了~~~~

```shell
$ sudo snap install qv2ray
```

---

#### 2.安装v2ray核心

从github上下来linux通用的v2ray-linux-64，然后找个地方解压。然后打开qv2ray，在首选项/内核设置/中添加`核心可执行文件路径`和`v2ray资源目录`。

`核心可执行文件路径`是解压路径下的**v2ray**可执行文件，`v2ray资源目录`是**v2ray**所在的目录。添加好进行检测，看是否能用。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200613032631325.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2R1YXBwbGU=,size_16,color_FFFFFF,t_70)
---

#### 3.测试

添加订阅，然后给浏览器火狐装插件——SwitchyOmega。配置以下代理协议，ip和端口号，选择proxy即可。

Google Chrome的话是先要上google才能下载插件。命令行使用`google-chrome-stable --help` (不行就是`google-chrome --help`)，或者`man google-chrome-stable`，查看设置代理的方法。找到**socks5**的那行，提供了设置示例。设置好后进入google chrome 下载上面的插件即可。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200613032641180.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2R1YXBwbGU=,size_16,color_FFFFFF,t_70)
关于其它软件的代理方法，都是通过命令行工具**proxychains**实现。具体操作可以参考我的另外一片帖子：https://blog.csdn.net/duapple/article/details/106299011