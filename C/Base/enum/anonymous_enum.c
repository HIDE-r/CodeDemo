#include <stdio.h>
 
struct person
{
    char    *name;
    union
    {
        char gender;
        int  id;
    };
    int      age;
};
 
int main(void)
{
    struct person jim = {"jim", 'F', 28};
 
    printf("jim.gender = %c, jim.id = %d\n", jim.gender, jim.id);
 
    return 0;

}
