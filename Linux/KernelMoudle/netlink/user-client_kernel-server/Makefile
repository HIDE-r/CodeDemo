KBUILD_CFLAGS += -w
obj-m += netlink_kernel.o

all: kernel_module user

kernel_module:
	make -w -C ${KERNEL_DIR} M=$(PWD) modules

user:
	gcc netlink_user.c -o netlink_user

clean:
	make -C ${KERNEL_DIR} M=$(PWD) clean
	rm netlink_user
