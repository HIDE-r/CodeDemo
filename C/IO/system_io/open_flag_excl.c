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
	
	//检测文件是否存在
	int fd = open(argv[1],O_RDWR|O_CREAT|O_EXCL,0777);
		if(fd < 0)
		{
			perror("open fail:");   //当文件打开出错时，做出错处理
			
			if( errno == EEXIST)   //判断错误宏
			{
				
				printf("当前需要创建的文件已经存在了是否覆盖\n");
				
			}			
			
			return -1;
		}
		else 
		{
			printf("open OK\n");
		}
	
	
	
}