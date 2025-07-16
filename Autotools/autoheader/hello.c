#include <stdio.h>
#include "config.h"

int main() {
#ifdef DEBUG
    printf("DEBUG mode is enabled\n");
#endif

#ifdef HAVE_STRDUP
    printf("Your system supports strdup!\n");
#else
    printf("No strdup() on your system!\n");
#endif
    return 0;
}
