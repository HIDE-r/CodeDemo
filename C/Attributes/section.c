#include <stdlib.h>
#include <stdio.h>

// section, 指定函数或变量所在的段
__attribute__((section("my_section")))
void foo(void) 
{
	printf("This function is in a custom section.\n");
}

int main(int argc, char *argv[])
{
	return EXIT_SUCCESS;
}
