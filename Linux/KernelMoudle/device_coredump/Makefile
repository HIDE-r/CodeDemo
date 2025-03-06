KERNEL_DIR:=/home/collin/Public/Project/x86/linux
KBUILD_CFLAGS += -w
DEPEND_OBJ:=demo_main.o

obj-m+=demo.o
demo-objs := $(DEPEND_OBJ)

all:
	make -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	rm -rf *.order *.o .*.o *.symvers *.mod.c *.mod *.ko .*.cmd
