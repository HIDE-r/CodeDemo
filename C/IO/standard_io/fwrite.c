#include  <stdio.h>

int main()
{
	

	FILE *fp = fopen("./my.txt","r+");
		 if(fp == NULL)
		 {
			 perror("fopen fail:");
			 return -1;
		 }
	
	
	// /往文本中写入一个  INT 类型的数据 

	//int   a=10086; 
	//fwrite(&a,4,1,fp);

	//读取一个int  类型的数据 
	int a=0;
	fread(&a,4,1,fp);
	printf("%d\n",a);

	fclose(fp);

		
}