#include <stdio.h>
#include <string.h>

struct student
{
		int age;
		char name[20];
		float score;
};

typedef struct man  			//给结构体取别名，名字为stu
{
	float high;
}stu;

struct people
{
	int teacher;
	stu a;
};


int main()
{
	struct student zhangsan;
	zhangsan.age = 20;
	zhangsan.score = 59.9;
	//zhangsan.name = "zhangsan";//这是错误的，数组除了初始化不能整体赋值
	strcpy(zhangsan.name,"zhangsan");

	printf("zhangsan.age = %d\n",zhangsan.age );
	printf("zhangsan.score = %lf\n",zhangsan.score );
	printf("zhangsan.name = %s\n",zhangsan.name );
	printf("**************************************\n");

	//定义以及初始化方式一
	struct student lisi = {21,"lisi",65.5};
	printf("lisi.age = %d\n",lisi.age );
	printf("lisi.score = %lf\n",lisi.score );
	printf("lisi.name = %s\n",lisi.name );
	printf("**************************************\n");

	//定义以及初始化方式二，可以实现乱序，也可以不进行所有成员赋值
	struct student wangwu = 
						{
							.name = "wangwu",
							.score = 61.1,
							//.age = 22			//也可以不进行所有成员赋值
						};
	printf("wangwu.age = %d\n",wangwu.age );
	printf("wangwu.score = %lf\n",wangwu.score );
	printf("wangwu.name = %s\n",wangwu.name );
	printf("**************************************\n");


	//若结构体内输入错误，则可以用指针操作
	struct student *p = &wangwu;
	p->score = 21;
	strcpy(p -> name,"naocan");//p->name，意思是p指向的地址下的name，所以是一个数组
	printf("wangwu.age = %d\n",wangwu.age );
	printf("wangwu.score = %lf\n",wangwu.score );
	printf("wangwu.name = %s\n",wangwu.name );
	printf("**************************************\n");	

	stu xxx;
	xxx.high = 1.78;
	printf("xxx.high = %lf\n",xxx.high );
	printf("**************************************\n");

	struct people peo;
	peo.teacher = 20;
	peo.a.high = 1.75;
	printf("peo.a.high = %lf\n",peo.a.high );
}