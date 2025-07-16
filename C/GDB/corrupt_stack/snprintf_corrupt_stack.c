#include <stdlib.h>
#include <stdio.h>

struct node{
	int id;
	struct node *next;
};

void func()
{
	char buf[256];
	struct node *ptr = NULL;

	snprintf(buf, sizeof(buf), "%s\n", ptr->next);
}

int main(int argc, char *argv[])
{
	func();

	return EXIT_SUCCESS;
}
