
src := $(foreach d, $(srcdir), $(wildcard $(d)/*.c))
obj := $(src:.c=.o)
dep := $(src:.c=.d)
build := $(BUILD_DIR)/$(subst $(ROOT_DIR)/,,$(CURDIR))
objs := $(addprefix $(build)/, $(obj))
deps := $(addprefix $(build)/, $(dep))
lib_target := $(outdir)/$(target)

all: $(lib_target)

#-----------------------------------------------
# ���ɾ�̬�⼰������ϵ
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
# ����.o�ļ�������������ϵ
#-----------------------------------------------
$(build)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

#-----------------------------------------------
# ����.d�ļ�������������ϵ
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