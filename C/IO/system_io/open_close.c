#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
   
int main()
{
	
		//调用open 函数去打开一个文件 
		int  fd = open("./my.txt",O_RDWR); 
			if(fd < 0)
			{
				perror("open fail:");  //输出错误信息 
				return -1; 
			}
			else 
			{
				printf("open ok %d\n",fd);
				
				//释放设备  
				close(fd);
			}

	
	//练习:看看可以无限打开一个文件不？？？？？
	
	return 0;
}
