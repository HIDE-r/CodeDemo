/**
 * 编译链接时, 需要指定 -rdynamic 参数
 */

#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>

// 定义一个函数，用于打印调用堆栈
void print_backtrace() {
    void* callstack[128];
    int frames = backtrace(callstack, sizeof(callstack) / sizeof(void*));

    char** strs = backtrace_symbols(callstack, frames);

    if (strs == NULL) {
        perror("backtrace_symbols");
        exit(EXIT_FAILURE);
    }

    printf("Call Stack:\n");
    for (int i = 0; i < frames; i++) {
        printf("%s\n", strs[i]);
    }

    free(strs);
}

// 一个用于演示的递归函数
void func_c(int depth) {
    if (depth == 0) {
        print_backtrace();
        return;
    }

    func_c(depth - 1);
}

void func_b() {
    func_c(2);
}

void func_a() {
    func_b();
}

int main() {
    printf("Starting backtrace demo...\n");
    func_a();
    return 0;
}

