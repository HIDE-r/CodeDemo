#include <stdio.h>
#include <stdlib.h>

// 默认除法会向下取整, 为了达到四舍五入的效果, 可以使用以下函数
// 思路: 将被除数加上除数的一半, 即余数将扩大除数的一半, 然后再进行除法运算. 当余数大于等于除数的一半时, 则向上取整, 否则向下取整.
div_t div_round(int dividend, int divisor)
{
	int tmp = dividend + (divisor / 2);
	return div(tmp, divisor);
}

int main(int argc, char *argv[])
{
	div_t result = div_round(11, 3); // 结果为4

	printf("Result of rounding division: %d\n", result.quot);
	return EXIT_SUCCESS;
}
