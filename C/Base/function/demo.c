//8.编写一个程序，清除用户输入字符串中的空格符并将之输出。（例如用户输入“a b”，输出“ab”）
#include <stdio.h>
#include <string.h>

char * clear_space(char * p);

int main (void)
{
	char string[50];
	printf("please input a string:");
	fgets(string,50,stdin);
	string[strlen(string) - 1] = '\0';

	char *p = clear_space(string);
	printf("after erase the space,the string is:%s\n",p );

}

char * clear_space(char * p)
{
	int i,j;
	for(i = 0;i < strlen(p);i++)
	{
		if( p[i] == ' ' )
		{
			for(j = 0;j < strlen(p) - i -1;j ++)
			{
				p[i + j] = p[i + j + 1];
			}
			p[strlen(p) - 1] = '\0';
			if( p[i] == ' ')
			{
				i--;
			}
		}

	}
	return p;
}