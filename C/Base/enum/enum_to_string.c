#include <stdio.h>
#include <stdlib.h>

#define FOREACH_FRUIT(FRUIT) \
        FRUIT(apple, 11)   \
        FRUIT(orange)  \
        FRUIT(grape, 20)   \
        FRUIT(banana)  \


#define GET_MACRO(_1, _2, NAME, ...) NAME

#define GENERATE_ENUM_1(ENUM) ENUM,
#define GENERATE_ENUM_2(ENUM, VALUE) ENUM = VALUE,
#define GENERATE_STRING(STRING, ...) [STRING]=#STRING,

#define GENERATE_ENUM(...) GET_MACRO(__VA_ARGS__, GENERATE_ENUM_2, GENERATE_ENUM_1)(__VA_ARGS__)


enum FRUIT_ENUM {
    FOREACH_FRUIT(GENERATE_ENUM)
};

static const char *FRUIT_STRING[] = {
    FOREACH_FRUIT(GENERATE_STRING)
};

int main(int argc, char *argv[])
{
	printf("string for enum(%d)=%s\n", apple, FRUIT_STRING[apple]);
	printf("string for enum(%d)=%s\n", orange, FRUIT_STRING[orange]);
	printf("string for enum(%d)=%s\n", grape, FRUIT_STRING[grape]);
	printf("string for enum(%d)=%s\n", banana, FRUIT_STRING[banana]);
	return EXIT_SUCCESS;
} 
