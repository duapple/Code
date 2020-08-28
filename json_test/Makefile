CC = gcc
TARGET = test
DIR0 = ./cJSON
DIR1 = ./cJSON/src
DIR2 = .
LDFLAGS = 
CFLAGS = -g 
INCLUDE = -I$(DIR0)/include -I$(DIR2)
SRCS = $(DIR1)/cJSON.c \
       $(DIR1)/cJSON_Utils.c \
	   $(DIR2)/util.c \
	   $(DIR2)/main.c

OBJ_DIR = ./build
TMP_DIR = $(OBJ_DIR)

OBJS = $(SRCS:.c=.o)

INC = $(SRC:.c=.h)

$(TARGET): $(addprefix $(TMP_DIR)/,$(OBJS))
	$(CC) -o $@ $^ $(LDFLAGS)

 
clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*/*.o $(DIR2)/TARGET


$(addprefix $(TMP_DIR)/,%.o):%.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $<  -o $@   
