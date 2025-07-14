#include <stdio.h>

// constructor, 作用为自动在main函数之前执行
// constructor (priority)	设置优先级, 范围 101 ~ 65535, 优先级的值越低越先执行

static void __attribute__((constructor)) constructor(void) {
    // This function will be called before main()
    // You can put any initialization code here
    printf("Constructor called before main()\n");
}

int main(int argc, char *argv[]) {
    // Your main code here
    printf("Main function\n");

    return 0;
}
