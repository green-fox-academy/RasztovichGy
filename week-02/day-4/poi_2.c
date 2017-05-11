#include <stdio.h>

int main() {
    int number = 1234;
    int* number_pointer = &number;
    //TODO:
    // print the value of number using the "number_pointer"

    printf("Address \t Value\n");
    printf("%p \t %d \n", number_pointer, number);
    return 0;
}
