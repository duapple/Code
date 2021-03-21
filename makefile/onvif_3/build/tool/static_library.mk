
src := $(foreach d, $(srcdir), $(wildcard $(d)/*.c))
obj := $(src:.c=.o)
dep := $(src:.c=.d)
build := $(BUILD_DIR)/$(subst $(ROOT_DIR)/,,$(CURDIR))
objs := $(addprefix $(build)/, $(obj))
deps := $(addprefix $(build)/, $(dep))
lib_target := $(outdir)/$(target)

all: $(lib_target)

#-----------------------------------------------
# 生成静态库及依赖关系
#-----------------------------------------------
$(lib_target):$(objs)
	@mkdir -p $(build)/$(srcdir)
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

.PHONY: clean
clean:
	@echo "cleanning ..."
	-@rm -f $(lib_target) $(objs)
	@echo "clean completed."