#include <stdio.h>
#include <stdio.h>
  #include <sys/types.h>
       #include <unistd.h>
	     #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

#include  <errno.h>  //错误宏  ，linux 系统中的所有错误信息都在该宏中 
						//errno      
int main(int argc,char *argv[])
{
	
	if(argc != 2)
	{
		printf("请输入需要创建的文件\n");
	}
	
	//O_TRUNC是 truncate，截断的意思。当打开文件时，文件的长度会截为0，即清空之前的文件内容
	//否则会出现的情况：文件原本内容为：bbbbb，当打开文件时写入aaa，发现文件结果为aaabb。
	int fd = open(argv[1],O_RDWR|O_CREAT|O_TRUNC,0777);
		if(fd < 0)
		{
			perror("open fail:");   //当文件打开出错时，做出错处理	
			return -1;
		}
		else 
		{
			printf("open OK\n");
		}
	
	
	
}
