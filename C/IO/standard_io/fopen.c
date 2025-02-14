#include  <stdio.h>

int main()
{
	

	FILE *fp = fopen("./my.txt","r+");
		 if(fp == NULL)
		 {
			 perror("fopen fail:");
			 return -1;
		 }
	
	

	printf("fp->_fileno=%d\n",fp->_fileno);
	

	printf("fp->_IO_buf_base=%p\n",fp->_IO_buf_base);
	printf("fp->_IO_buf_end=%p\n",fp->_IO_buf_end);
	 
	 
	char buf[100]={0};
	size_t  ret=fread(buf,sizeof(char),100,fp);
		printf("ret=%ld  buf=%s\n",ret,buf);
	
	printf("read fp->_IO_buf_base=%p\n",fp->_IO_buf_base);
	printf("read fp->_IO_buf_end=%p\n",fp->_IO_buf_end);

	printf("当前缓存区的大小%d\n",fp->_IO_buf_end -fp->_IO_buf_base);	
		
}