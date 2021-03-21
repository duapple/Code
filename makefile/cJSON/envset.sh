#!/bin/bash
# 运行：source envset.h

#------------------------------
# 选择编译工具链
#------------------------------
CROSS=
#arm-himix100-linux-
export CC=${CROSS}gcc
export AR=${CROSS}ar
echo ">> select toolchain [$CC]"

#------------------------------
# 全局编译参数变量
#------------------------------
export CFLAGS_ENV="-Wall -Os -ffunction-sections -fdata-sections"
#-g 

#-------------------------------
# 全局编译路径变量
#-------------------------------
export ROOT_DIR=$(pwd)
export mk_dir=$(pwd)/build/tool
export BUILD_DIR=$ROOT_DIR/build/out
export APP_DIR=$ROOT_DIR/app
export MOD_DIR=$ROOT_DIR/mod
