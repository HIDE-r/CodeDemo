#include <stdio.h>

int main()
{
	int i,j,k,num;// 循环变量
	char letter;
	printf("please input a letter:");
	scanf("%c",&letter);


	if(letter >= 65 && letter <= 90)				//判断输入的是大写还是小写字母
	{
		num = letter - 64;              			//A的ASCII码为65,a的ASCII码为97
	}
	else if(letter >= 97 && letter <= 122)
	{
		num = letter - 96;
	}


	for(i = 0;i < num;i++) 						//打印上半部分
	{
		for(j = 0;j < num - 1 -i;j++)
		{		
			printf(" ");
		}


		for(j = 0;j < 2*i+1;j++)
		{		
			if(j < (2 * i + 1)/2 + 1)
			{
				
				printf("%c",j+65 );
			}
			else
			{
				printf("%c",65 + i - (j + 1 - ((2 * i + 1)/2 + 1)) );
			}
		}
		printf("\n");
			
	}

	
	for(i = 0;i < num - 1;i++)					//打印下半部分
	{
		for(j = 0;j < i+1;j++)
		{
			printf(" ");
		}
		for(j = 0;j < (num - 2 - i)*2 + 1;j++)
		{
			if(j < ((num - 2 - i)*2 + 1)/2 + 1)
			{
				
				printf("%c",j+65 );
			}
			else
			{
				printf("%c",65 + (num - 2 - i) - (j + 1 - ((2 * (num - 2 - i) + 1)/2 + 1)) );
			}

		}
		printf("\n");
	}
	
}