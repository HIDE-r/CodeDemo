#include <stdio.h>

int main(void)
{
    int arr[] = { 1, 3, 5, 7, 9};
    int len = sizeof(arr) / sizeof(int);  //求数组长度
    int i;
	
    for(i=0; i<len; i++) 
    {
        printf("*(arr+%d) = %d\n",i, *(arr+i) ); 
		
    printf("\n");
	}
    return 0;
} 