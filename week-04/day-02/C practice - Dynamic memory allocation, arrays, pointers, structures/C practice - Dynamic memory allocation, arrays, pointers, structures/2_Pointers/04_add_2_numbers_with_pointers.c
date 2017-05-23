#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Add two numbers using pointers
*/

int main()
{
    int a = 20;
    int b = 17;

    printf("Az a erteke dec-ben: %d, hex-ben: %x\n", a, a);
    printf("Az @a erteke dec-ben: %d, hex-ben: %x\n", &a, &a);
    printf("A *a-nak meg nincs erteke.\n");

    printf("\n-------------------------------------\n");
    printf("Most definialjuk hogy int *a_ptr = &a\n");
    int *a_ptr = &a;
    int *b_ptr = &b;
    printf("--------------------------------------\n");

    printf("A *a_ptr=&a erteke dec-ben: %d, hex-ben: %x\n", *a_ptr, *a_ptr);
    printf("Az @a erteke dec-ben: %d, hex-ben: %x\n", &a, &a);
    printf("\n--------------------------------------\n");
    printf("Ta-daaamm - pointerrel vegzunk muveletet valtozokkal, juhhey!\n");
    printf("a+b pointerekkel osszeadva: %d\n", *a_ptr + *b_ptr);

    return 0;
}
