#include <stdio.h>

static void __attribute__((destructor)) destructor(void) {
    // This function will be called after main()
    // You can put any cleanup code here
    printf("Destructor called after main()\n");
}

int main(int argc, char *argv[]) {
    // Your main code here
    printf("Main function\n");

    return 0;
}
