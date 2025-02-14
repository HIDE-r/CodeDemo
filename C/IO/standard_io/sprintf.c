#include <stdio.h>
int main()
{

	char *str  = "我好";  

	char *str1  = "你好";  

 
	//sprintf  做字符串数据的拼接  
	char buf[1024]={0};
 	sprintf(buf,"%s:%s:大家好，才是真的好！",str,str1);
	
	printf("buf=%s\n",buf);





}
