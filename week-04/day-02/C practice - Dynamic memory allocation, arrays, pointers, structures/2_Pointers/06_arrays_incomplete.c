#include <stdio.h>

int main()
{
    int numbers[] = {5, 6, 7, 8, 9};
    int *number_pointer;
    //TODO:
    // The "number_pointer" should point to the first element
    // of the array called "numbers",
    // than please print its value with it.
    number_pointer = numbers;
    printf("%x\n", *number_pointer);
//wáááááááááááááááá
    for(int i = 0; i < 5; i++) {
        printf("%d\n", numbers[i]);
    }
    for(int i = 0; i < 5; i++) {
        printf("%d\n", number_pointer);
    }

    return 0;
}
