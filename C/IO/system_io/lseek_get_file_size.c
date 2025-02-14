#include <stdio.h>
  #include <sys/types.h>
       #include <unistd.h>
	     #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
//main 函数传参   
int  main(int argc,char *argv[])
{
	//char  *p[10]; 数组，先看优先级 [] 优先级高，所以是数组 
	//char  (*p)[10]; 指针 先看优先级 () 优先级高,所以是指针 
	
	/*
	printf("argc =%d\n",argc);
	printf("argv[0]=%s\n",argv[0]);
	printf("argv[1]=%s\n",argv[1]);
	printf("argv[2]=%s\n",argv[2]);
	*/  
	//判断用户输入的参数个数 
	 if(argc != 2)
	 {
		printf("请输入参数有误  ./main  filename\n");
		return -1;
	 }
	
	
	
	 //打开对应的文件  
		int  fd = open(argv[1],O_RDWR); 
			if(fd < 0)
			{
				perror("open fail:");  //输出错误信息 
				return -1; 
			}
			else 
			{
				printf("open ok %d\n",fd);
				
			
			}
			
	  //利用LSEEK 获取文件的大小 
	 int  filesize =  lseek(fd,0,SEEK_END); // 把文件光标偏移到文件的末尾 
		  printf("当前的文件大小为 %d\n",filesize);
}