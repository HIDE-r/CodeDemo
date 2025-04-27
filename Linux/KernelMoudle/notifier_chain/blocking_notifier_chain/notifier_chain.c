#include <linux/module.h>
#include <linux/init.h>
#include <linux/notifier.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("collin");
MODULE_DESCRIPTION("Notifier Chain Example");

// 定义阻塞型通知链
BLOCKING_NOTIFIER_HEAD(my_notifier_chain);

// 注册函数
int register_my_notifier(struct notifier_block *nb) {
    return blocking_notifier_chain_register(&my_notifier_chain, nb);
}

// 注销函数
int unregister_my_notifier(struct notifier_block *nb) {
    return blocking_notifier_chain_unregister(&my_notifier_chain, nb);
}

// 调用通知链
int call_my_notifier(unsigned long val, void *v) {
    return blocking_notifier_call_chain(&my_notifier_chain, val, v);
}

// 示例监听者
static int example_event_handler(struct notifier_block *nb,
                                 unsigned long action, void *data)
{
    pr_info("Notifier callback triggered: action = %lu, data = %s\n",
            action, (char *)data);
    return NOTIFY_OK;
}

static struct notifier_block my_notifier = {
    .notifier_call = example_event_handler,
};

// 模块加载时注册
static int __init notifier_init(void)
{
    pr_info("Notifier Example: module init\n");

    register_my_notifier(&my_notifier);

    call_my_notifier(1, "Hello Notifier!");

    return 0;
}

// 模块卸载时注销
static void __exit notifier_exit(void)
{
    pr_info("Notifier Example: module exit\n");

    unregister_my_notifier(&my_notifier);
}

module_init(notifier_init);
module_exit(notifier_exit);

