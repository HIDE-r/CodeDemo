#include <stdio.h>
#include <string.h>
int main()
{

	FILE *fp = fopen("my.txt","r+");


	char buf[1024];
	
	//gets(buf); // 从键盘 获取 一行数据  
     fgets(buf,1024,fp);  

     printf("buf=%s\n",buf);

      printf("buf=%ld\n",strlen(buf));



}
