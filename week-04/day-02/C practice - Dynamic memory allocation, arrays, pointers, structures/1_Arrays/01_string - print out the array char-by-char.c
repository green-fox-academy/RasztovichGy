#include <stdio.h>

int main()
{
    char my_name_array[] = "My Name";

    //TODO:
    // Print out the array character-by-character
    for (int i = 0; i < sizeof(my_name_array); i++)
        printf("%dth character:\t%c\n", i+1, my_name_array[i]);

    printf("\n%d", strlen(my_name_array)); //tényleg 7 szám hosszú az array.
    printf("\n%d", sizeof(my_name_array)); //a mérete viszont 8.
    return 0;
}
