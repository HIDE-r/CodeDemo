#include <stdio.h>

int main(void)
{
	int i;
	int num;
	int (*p)[5] = NULL;  //数组指针  
	int arr[5] =  {5,2,4,5,7};
	p = &arr;
	

	
	printf("=====================================\n");
	num = sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<num;i++)
	{
		printf("*p[%d] = %d\n",i,*p[i]);//*(*(p + i))
	}
	printf("=====================================\n");
 	for(i=0;i<num;i++)
	{
		printf("*(p+%d) = %p\n",i,*(p+i));  
	} 
	printf("=====================================\n");
	
	for(i=0;i<num;i++)
	{
		printf("p[%d] = %p\n",i,p[i]);  //   = *(p + i)，即与上面相同 
	}
	printf("=====================================\n");
	
	for(i=0;i<num;i++)
	{
		printf("(*p)[%d] = %d\n",i,(*p)[i]); 
	}
	
	return 0;
}