//5.编写一个程序，将两个字符串连接起来，不要用strcat 或strncat 函数
#include <stdio.h>
#include <string.h>

char * link_string(int len1,char *str1,int len2,char *str2);

int main (void)
{
	char str1[50],str2[50];

	printf("please input the first string:");
	fgets(str1,25,stdin);
	printf("please input the second string:");
	fgets(str2,25,stdin);

	str1[strlen(str1) - 1] = '\0';
	str2[strlen(str2) - 1] = '\0';
	printf("strlen(str1) = %lu\n", strlen(str1));
	printf("strlen(str2) = %lu\n", strlen(str2));
	//printf("%s", str1);
	char * p = link_string(strlen(str1),str1,strlen(str2),str2);
	p[strlen(str1) + strlen(str2)] = '\0';
	
	printf("after link up ,the first string become:%s\n",p );
}

char * link_string(int len_desk,char *str_desk,int len_src,char *str_src)
{
	int i;
	char box_str[len_desk + len_src ];
	for(i = 0;i < len_desk;i++)
	{
		box_str[i] = str_desk[i];
	}

	for(i = len_desk;i < len_desk + len_src;i++)
	{
		
		box_str[i] = str_src[i - len_desk];
	}
	
	return box_str;	
}