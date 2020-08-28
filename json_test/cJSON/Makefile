
#------------------------------------
# module name
#------------------------------------
TARGET := libcJSON

#------------------------------------
# include directorys
#------------------------------------
OUT_DIR := $(CURDIR)/lib

#------------------------------------
# include make tools
#------------------------------------
include $(BUILD_TOOLS_DIR)/base.mk

#------------------------------------
# source files
#------------------------------------
SRC_FILES :=
SRC_FILES += $(call get_src_files, $(CURDIR))

#------------------------------------
# include directorys
#------------------------------------
INC_DIRS := 
INC_DIRS += $(call get_inc_dirs, $(CURDIR))


#------------------------------------
# private compiler options
#------------------------------------
MY_CFLAGS :=

#------------------------------------
# private compiler options
#------------------------------------
MY_CPPFLAGS :=

#------------------------------------
# target
#------------------------------------
include $(BUILD_TOOLS_DIR)/static_library.mk
