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


$(TARGET):$(OBJS)
	$(CC) -o $@ $(addprefix $(OBJ_DIR)/,$^) $(LDFLAGS)

 
clean:
	rm -f  $(OBJ_DIR)/*.o server


%.o:%.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $<  -o $(OBJ_DIR)/$@ 
