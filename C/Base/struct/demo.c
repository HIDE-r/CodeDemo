#include <stdio.h>
#include <string.h>

typedef union 
{
	/long i[2];
	// short a[12];
	char b[19];
	char c;
}fruit;

struct creature
{
		int cat ;
		int w;
		//fruit apple;
		double dog;
};

int main()
{
	fruit lisi;
	printf("sizeof(fruit) = %lu\n",sizeof(fruit) );
	printf("sizeof(lisi) = %lu\n",sizeof(lisi) );
	printf("sizeof(struct creature)  = %lu\n",sizeof(struct creature) );
}
