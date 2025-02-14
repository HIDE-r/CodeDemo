#include <stdio.h>
#include <string.h>

struct student
{
	// unsigned short cat;
	long b;
};

struct man
{
	char name[6];
	
	int a;
	struct student lili;
};
//计算结构体大小需要字节对齐
int main()
{
	printf("sizeof(struct student) = %lu\n",sizeof(struct student) );
	printf("sizeof(struct man) = %lu\n",sizeof(struct man) );
}
