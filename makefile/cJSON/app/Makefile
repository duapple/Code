
#------------------------------
# 生成程序名称
#------------------------------
target := main

#------------------------------
# 生成程序输出路径
#------------------------------
outdir := $(ROOT_DIR)

#------------------------------
# .c源文件
#------------------------------
src := $(wildcard *.c)

#------------------------------
# 链接参数
#------------------------------
LDLAGS := -Wl,-Map=object.map,--cref,--gc-section -lpthread -ldl -lm

#------------------------------
# 链接时需要的头文件
#------------------------------
# INCLUDE := -I$(MOD_DIR)/onvif/include
INCLUDE := -I$(MOD_DIR)/cJSON/include

#------------------------------
# 模块路径
#------------------------------
MOD += cJSON
# MOD += gsoap
# MOD += onvif
# MOD += openssl

#------------------------------
# 链接时需要的库
#------------------------------
LIB += $(foreach d, $(addsuffix /lib, $(addprefix $(MOD_DIR)/, $(MOD))), $(wildcard $(d)/*.a))

all: $(outdir)/$(target)

$(outdir)/$(target): $(LIB) $(src)
	$(CC) -o $(outdir)/$(target) $(src) $(INCLUDE) -Xlinker "-(" $(LIB) -Xlinker "-)" $(LDLAGS)

.PHONY: clean
clean:
	-@rm -f $(outdir)/$(target)
