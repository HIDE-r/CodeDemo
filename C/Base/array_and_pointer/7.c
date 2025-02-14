#include <stdio.h>

int main(void)
{
    int a = 1, b = 2, c = 3;
    int *arr[3] = {&a, &b, &c};//整型指针数组
    int **parr = arr;
	
    printf("%d, %d, %d\n", *arr[0], *arr[1], *arr[2]);
    printf("%d, %d, %d\n", **(parr+0), **(parr+1), **(parr+2));//*（parr + 0 ） = &a
    return 0;
}