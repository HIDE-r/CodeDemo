#include <stdio.h>

int main(void)
{
	int (*p)[5] = NULL;   //数组指针
	int arr[5] = {1,2,4,5,7};
	p = &arr;

	printf("arr    = %p\n",arr );  	//即数组首元素地址 == &arr[0]	
	printf("&arr   = %p\n",&arr );    //整个数组的地址 == 数组首元素地址
	printf("p      = %p\n",p);        //p的内容是数组的地址
	printf("*p     = %p\n",*p );     //*p = *&arr = arr，即arr数组的地址
	printf("p+1    = %p\n",p+1 );    //指向整个数组后的一个地址
	printf("(*p)+1 = %p\n",(*p)+1);    //arr[1] == 2的地址

	
	return 0;
}