#include <stdio.h>

int * calc_string(char *string,int length);

int main(int argc, char const *argv[])
{
	int length;
	printf("please input your string array length:");
	scanf("%d",&length);

	getchar();

	char string[length];
	printf("please input a string:");
	fgets(string,length,stdin);
	printf("******************************************\n");
	printf("this is your input string:%s\n",string );

	int *p = calc_string(string,length);

	printf("the number of the blank space is :%d\n",p[0]);
	printf("the number of the numbers is :%d\n",p[1]);
	printf("the number of the letter is :%d\n",p[2]);
	printf("the number of the other Symbol is：%d\n",p[3] - 1);//减1，减去最后的'\0'

	return 0;
}

/*
	功  能：计算字符串中字母、数字、空格、和其他字符的个数
	参  数：char *string  ——————>字符串数组地址
			int  length  ——————>字符串长度
	返回值：存放字母、数字、空格、和其他字符的个数的数组的地址
*/
int * calc_string(char *string,int length)
{
	int i,j,blank =0,calc_num = 0,calc_letter = 0;
	char numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
	for(i = 0;i < length;i++)//检索字符串中空格的数量
	{
		if(string[i] == ' ')//a的ascll码为97，z的ascll码为122
		{
			blank++;
		}	
	}

	for(i = 0;i < length;i++)//检索字符串中数字的数量
	{
		for(j = 0;j < 10;j++)
		{
			if(numbers[j] == string[i])
			{
				calc_num++;
			}
		}
	}

	for(i = 0;i < length;i++)//检索字符串中字母的数量
	{
	
		if(string[i] >=97 && string[i] <= 122)//a的ascll码为97，z的ascll码为122
		{
			calc_letter++;
		}	
	}


	int arr[4] = { blank, calc_num, calc_letter, length -(calc_num + calc_letter + blank) };
	return (arr);
}

