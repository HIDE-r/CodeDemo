#include <stdio.h>

int main(void)
{
    int arr[] = { 1, 3, 5, 7, 9};
    int i, *p = arr, len = sizeof(arr) / sizeof(int);
	
    for(i=0; i<len; i++)
    {
        printf("%d\n", *p++ );  
		printf("%d\n", (*p)++ ); 
        printf("\n");
    }
    
	
    return 0;
}