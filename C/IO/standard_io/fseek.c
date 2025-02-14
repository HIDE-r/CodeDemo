#include <stdio.h>

int main(int argc,char *argv[])
{

	FILE  *fp  = fopen(argv[1],"r");  
		if(fp == NULL)
		{
		   return 0;

		}

	//把文件光标偏移到文件的末尾  
  int  ret = 	fseek(fp,0,SEEK_END); 
	if(ret == 0)
	{
		printf("当前文件的大小为%ld\n",ftell(fp));
	}
	else
	{
	    printf("获取文件大小失败\n");

	}


}
