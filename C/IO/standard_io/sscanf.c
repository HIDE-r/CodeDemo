#include <stdio.h>

int main()
{

	char buf[100]={"陈小小 18 20190808 游泳"}; 

	char name[100]= {0}; 
	int  age      =  0; 
	long long  id =  0;
	char a[100]   ={0}; 

 	//做数据类型的转换
	sscanf(buf,"%s %d %lld %s",name,&age,&id,a); 

	printf("姓名=%s\n",name);
	printf("年龄=%d\n",age);
	printf("ID=%lld\n",id);
	printf("爱好=%s\n",a);

}
