#!/bin/bash
# ���У�source envset.h

# #------------------------------
# # ѡ����빤����
# #------------------------------
CROSS=
#arm-himix100-linux-
export CC=${CROSS}gcc
export AR=${CROSS}ar
echo ">> select toolchain [$CC]"

# #------------------------------
# # ȫ�ֱ����������
# #------------------------------
export CFLAGS_ENV="-ffunction-sections"

#-------------------------------
# ȫ�ֱ���·������
#-------------------------------
export ROOT_DIR=$(pwd)
export mk_dir=$(pwd)/build/tool
export BUILD_DIR=$ROOT_DIR/build/out
export APP_DIR=$ROOT_DIR/app
export MOD_DIR=$ROOT_DIR/mod