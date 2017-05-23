#include <stdio.h>

int main()
{
    int number = 1234;
    //int *number;
    //TODO:
    // print the memory address of the variable
    printf("The memory address of the variable in hex: %p\n", &number);
    printf("The memory address of the variable in hex: %x\n", &number);
    printf("The memory address of the variable in dec: %d\n", &number);
    printf("The decimal value of the variable: %d\n", number);
    return 0;
}

