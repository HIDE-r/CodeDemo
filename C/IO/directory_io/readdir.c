    #include <sys/types.h>
       #include <dirent.h>
#include <stdio.h>


int main()
{

#if 0
	//打开一个目录 
	DIR *p_fd = opendir("/home/gec");
	  if(p_fd == NULL)
	  {
	  	printf("打开目录失败\n" );
	  	return -1;
	  }

	  //读取一个目录中的信息  
	 、*
	 while(1)
	 {

     			  struct dirent *p = readdir(p_fd);
     			  if(p == NULL)
     			  {
     			  	printf("目录项读取完毕\n");
     			  	break;
     			  }
     			  printf("当前目录的文件名为：%s\n",p->d_name);

	 }
#endif


	DIR *dir = opendir("/home/gec");
	if(!dir){
		printf("打开目录失败\n");
		return -1;
	}

	struct dirent *dirp=NULL;
		
	while(1)
	{

		dirp = readdir(dir);

		if(dirp == NULL)
		{
			break;
		}

		if(dirp->d_name[0] == '.')  //假设是隐藏文件则跳过继续运行下一次循环
		{
			continue;
		}

		if(dirp->d_type == DT_REG)
		{
			printf("文件名为:%s\n", dirp->d_name);
		}
	}

	closedir(dir);

	return 0;

}



