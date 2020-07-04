SRCS = list.c \
       list_custom.c \
       main.c

OBJ_DIR = ./build
$(shell mkdir build)

OBJS = $(SRCS:.c=.o)

test: $(addprefix $(OBJ_DIR)/,$(OBJS))
	gcc $^ -o $@

clean:
	rm ./*.o ./build/*.o

$(addprefix $(OBJ_DIR)/,%o):%c
	gcc -c $< -o $@
