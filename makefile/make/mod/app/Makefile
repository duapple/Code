#------------------------------
# 生成程序名称
#------------------------------
target := app.a

#------------------------------
# 生成程序输出路径
#------------------------------
outdir := lib

#----------------------------------------
# 源文件路径（采用相对路径）
#----------------------------------------
srcdir := . src source

#----------------------------------------
# 头文件路径
#----------------------------------------
INCLUDE := -I./include 
INCLUDE += $(addprefix -I./, $(srcdir))

#----------------------------------------
# 编译参数
#----------------------------------------
CFLAGS := $(CFLAGS_ENV)

#------------------------------
# 编译前准备
#------------------------------
src := $(foreach d, $(srcdir), $(wildcard $(d)/*.c))
obj := $(src:.c=.o)
dep := $(src:.c=.d)
build := $(BUILD_DIR)/$(subst $(ROOT_DIR)/,,$(CURDIR)/)
objs := $(addprefix $(build)/, $(obj))
deps := $(addprefix $(build)/, $(dep))
target_out := $(outdir)/$(target)

all: $(target_out)

#-----------------------------------------------
# 生成静态库及依赖关系
#-----------------------------------------------
$(target_out):$(objs)
	@mkdir -p $(addprefix $(build)/, $(srcdir))
	@mkdir -p $(outdir)
	$(AR) -rc $@ $^
	@echo "-------------------------------------------"
	@echo "create $(target) successs."
	@echo "-------------------------------------------"

-include $(deps)

#-----------------------------------------------
# 生成.o文件的所有依赖关系
#-----------------------------------------------
$(build)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

#-----------------------------------------------
# 生成.d文件的所有依赖关系
#-----------------------------------------------
$(build)/%.d: %.c
	@set -e; mkdir -p $(@D); rm -f $@; \
	$(CC) -MM $(CFLAGS) $(INCLUDE) $< > $@.$$$$; \
	sed 's,\($(*F)\)\.o[ :]*,$(build)/$(<D)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$;\

#echo "generate dependencies $(@F) ."

.PHONY: clean clean_all

clean_all:
	-@rm -rf $(BUILD_DIR)

clean:
	@echo "cleanning ..."
	-@rm -f $(target_out) $(objs)
	@echo "clean completed."