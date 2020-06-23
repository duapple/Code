CC = gcc
OBJ_DIR = ./build
TARGET = test
SRCS = test.c \
       main.c

OBJS = $(SRCS:.c=.o)

$(TARGET):$(addprefix $(OBJ_DIR)/,$(OBJS))
	$(CC) $^ -o $@

$(addprefix $(OBJ_DIR)/,*.o):*.h

clean:
	rm *.o  $(OBJ_DIR)/*.o test

$(addprefix $(OBJ_DIR)/,%.o):%.c
	$(CC) -c $<  -o $@   