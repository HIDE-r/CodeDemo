//#define NDEBUG
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


int func(void)
{
	return 2;
}

void test(int num)
{
	assert(num == 1);
	printf("num = %i\n", num);
}

int main(int argc, char *argv[])
{
	int ret = func();

	test(ret);

	return EXIT_SUCCESS;
}
