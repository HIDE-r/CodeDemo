#include <stdio.h>

int main(void)
{

    int a[5] = {1,2,3,4,5};
    int b[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    printf("%p\n",&a);       //整个一维数组的地址
    printf("%p\n",&a+1);     //整个一维数组后的地址
    printf("%p\n",a);            // = &a[0]
    printf("%p\n",a+1);      //&a[1]


    printf("\n");
    printf("%p\n",&b);       //整个数组b的地址
    printf("%p\n",&b+1);     //数组b后的地址
    printf("\n");
    printf("%p\n",b);      // = b[0] = b[0][0]，即{1,2,3,4}数组的地址
    printf("%p\n",b+1);    // = b[1] = b[1][0]，即{5,6,7,8}数组的地址
    printf("\n");
    printf("*b   = %p\n",*b);       //*b就为{1,2,3,4}，而{1,2,3,4}又为b[0][0]的地址，即*b = b[0][0]的地址
    printf("*b+1 = %p\n",*b+1);     //b[0][0] + 1的地址
    printf("\n");
    printf("%d\n",**b);      //1
    printf("%d\n",**b+1);   //2

    return 0;
}