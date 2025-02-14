// 思路：将整型赋值一个数据如12，再以一个一个字符读出来，看哪个数据在前就能判断是小端还是大端了
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool func();

int main(int argc, char const *argv[])
{
	// 小端序：小数据放小地址，大数据大地址
	// 大端序：小数据大地址，大数据小地址
	bool tmp;

	if((tmp = func()) == 1)
	{
		printf("这是个小端序机器\n");
	}
	else{
		printf("这是个大端序机器\n");
	}


	return 0;
}

bool func()
{
	int a[2] = {1,2};
	char buf[50] = {0};
	int *p = (int *)((char*)a+1);
	//litte:01 00 00 00 | 02 00 00 00  ==>  01 |00 00 00 02 | 00 00 00
	//big:  00 00 00 01 | 00 00 00 02  ==>  00 |00 00 01 00 | 00 00 02
	sprintf(buf,"%x",*p);
	if(strcmp(buf,"20000000") == 0 ){
		printf("1\n");
		return 1;
	}
	if(strcmp(buf,"100") == 0 )
	{
		printf("0\n");
		return 0;
	}
		

}
