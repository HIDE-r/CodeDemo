//3.编写一个函数，使其返回3个整型参数中的最大值
#include <stdio.h>

int MAX(int a,int b,int c);

int main(int argc, char const *argv[])
{
	int arr[3],i;
	printf("please input three numbers:");
	for(i = 0;i < 3;i++)//循环赋值
	{
		scanf("%d",&arr[i]);
	}

	int max_arr = MAX( arr[0],arr[1],arr[2] );
	printf("the biggest numbers is:%d\n",max_arr);

	return 0;
}

int MAX(int a,int b,int c)
{
	int i,j,box;
	int abc[3] = { a,b,c };
	for(i = 0;i < 2;i++)
	{
		for(j = 0;j < 2 -i;j++)
		{
			if( abc[j] > abc[j + 1] )
			{
				box = abc[j];
				abc[j] = abc[j + 1];
				abc[j + 1] = box;
			}
		}
	}

	return abc[2];
}
