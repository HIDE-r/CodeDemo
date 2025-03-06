KBUILD_CFLAGS += -w
obj-m += netlink_kernel.o

all:
	make -w -C ${KERNEL_DIR} M=$(PWD) modules

clean:
	make -C ${KERNEL_DIR} M=$(PWD) clean
