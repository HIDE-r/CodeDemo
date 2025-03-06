#include <linux/module.h>
#include <linux/device.h>
#include <linux/devcoredump.h>

static struct device my_device;
static struct kmem_cache * network_isolate_cache = NULL;

#define INTERFACE_NUMS   3

struct if_name {
    char name[IFNAMSIZ];
};

struct network_isolate_info{
    int      rule_id;
    int      rule_mode;
    struct if_name if_array[INTERFACE_NUMS];
    u32     network_segment;                        //网段
    u32     mask;                      //掩码
};

struct network_isolate_node{
    struct  list_head     list_node;   
    rwlock_t    lock;                
    struct network_isolate_info rule;    
};

static void my_device_failure(struct device *dev) {
    char *buffer;
    size_t size = 1024;

    // 分配缓冲区
    buffer = kzalloc(size, GFP_KERNEL);
    if (!buffer)
        return;

    // 模拟收集设备状态信息
    snprintf(buffer, size, "Device state: register1=0x%x, register2=0x%x\n", 0x1234, 0x5678);

    // 触发 Device Coredump
    dev_coredumpv(dev, buffer, size, GFP_KERNEL);
}


static int __init network_isolate_init(void)
{
    network_isolate_cache = kmem_cache_create("dns_redirect_cache",
                            sizeof(struct network_isolate_node),
                            0, 0, NULL);

    struct device *dev = &my_device;

    // 模拟设备故障
    my_device_failure(dev);
    return 0;
}

static void __exit network_isolate_exit(void)
{  
    kmem_cache_destroy(network_isolate_cache);
}

module_init(network_isolate_init);
module_exit(network_isolate_exit);
MODULE_LICENSE("GPL");
