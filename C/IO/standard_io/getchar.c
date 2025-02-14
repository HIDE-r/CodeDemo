#include <stdio.h>

int main()
{


	//从标准输入设备中获取一个字符的数据
	int a = getchar();
	printf("a=%d\n",a );


	//从标准输入设备中获取一个字符的数据
	int b=fgetc(stdin);
	printf("b=%d\n",b);


}