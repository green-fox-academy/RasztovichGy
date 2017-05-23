#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *a,*b;
    a = malloc(sizeof(int));
    b = malloc(sizeof(int));
    *a=10;
    *b=20;

    printf("%d,%d",*a,*b);



    printf("\nHello world!\n");
    return 0;
}
