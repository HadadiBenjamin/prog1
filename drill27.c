#include <stdlib.h>
#include <stdio.h>

void print_out(const char* p, const int x)
{
    printf("p is \"%s\" and x is %i\n", p, x);
}

int main()
{
    
    printf("Hello World!\n");


    char* first = "Hello";
    char* last = "World!";
    printf("%s %s\n", first, last);


    print_out("Nov",22);
    print_out("Hada", 00);
    print_out("B", 90);
    return 0;
}