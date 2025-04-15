#include <stdio.h>
#include <string.h>

// size_t strspn(const char *str1, const char *str2);
// strspn函数从 str1 的第一个字符开始检查，依次判断每个字符是否存在于 str2 中。一旦遇到 str2 中不存在的字符，就停止检查并返回已经匹配的字符数量。
int main() {
    const char str[] = "123abc456";
    const char accept[] = "1234567890";

    size_t length = strspn(str, accept);

    printf("初始数字部分的长度是: %zu\n", length);  // 输出: 3
    return 0;
}
