
target := libssl.a libcrypto.a

lib = $(addprefix lib/, $(target))

all: $(lib)

$(lib):
ifeq ($(CC), arm-himix100-linux-gcc)
	cp lib_arm_gcc/*.a lib
else
	cp lib_gcc/*.a lib
endif

clean:
	-@rm -f lib/*.a