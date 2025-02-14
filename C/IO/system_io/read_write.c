#include <stdio.h>  
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h> 
  
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
				
			}

			
			
		//定义一个数据的缓冲区  
		char buf[1024]={0};  
		
		while(1)
		{
			
			scanf("%s",buf);
			//写入数据到文本中 
			int size = write(fd,buf,strlen(buf));
				printf("成功写入到数据为 %d\n",size);
				
		//从fd 中读取文件中的数据 
				bzero(buf,1024);  //清空数据

				//把光标偏移到文件头   
				lseek(fd,0,SEEK_SET);
				
		      size = read(fd,buf,1024);
			printf("size =%d buf=%s\n",size,buf);
		
		}
		
		
		//练习： 利用lseek 获取一个文件的大小 ？？？ 
		
	return 0;  
}
