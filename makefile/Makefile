CC = gcc 
TARGET = server 
GSOAP_ROOT = /mnt/i/Projects/IPC_onvif/gsoap-2.8
LDFLAGS = -lpthread
CFLAGS = -g -DWITH_NONAMESPACES
INCLUDE = -I$(GSOAP_ROOT) -I./util -I.
SRCS =  soapC.c \
		stdsoap2.c \
		soapServer.c \
		soapTester.c \
		util/util.c \
		onvif_util.c \
		onvif_probe.c \
		onvif_http.c \
		main.c

OBJ_DIR = ./build

OBJS = $(SRCS:.c=.o)

$(TARGET): $(addprefix $(OBJ_DIR)/,$(OBJS))
	$(CC) -o $@ $^ $(LDFLAGS)
 
clean:
	rm -f ./*.o $(OBJ_DIR)/*.o  $(OBJ_DIR)/*/*.o server


$(addprefix $(OBJ_DIR)/,%.o):%.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $<  -o $@   
