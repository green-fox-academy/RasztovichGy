#include <stdio.h>

int main()
{
    char char_array[] = {'a', 'b', 'c', '1', 'e'};
    char char_array_the_same[] = "abcde";

    //TODO:
    // Print out the two arrays character-by-character

    printf("A tombok hossza sizeof paranccsal:\n");
    printf("%d\n", sizeof(char_array)); //hoppá. a tömb hossza 6. ez nem oké így.
    printf("%d\n", sizeof(char_array_the_same));
    printf("-----------------\n");


    //egy sorba, egymásután kinyomtatva a kettõt
    printf("Egyetlen sorba kiirva a tomb elemeit\n");
    printf("%s\n", char_array);
    printf("%s\n", char_array_the_same);
    printf("-----------------------------------\n");

    for (int i = 0; i < sizeof(char_array); i++)
        printf("%dth character of first array:\t%c\n", i+1, char_array[i]);
    printf("-----------------------------\n");
    for (int i = 0; i < sizeof(char_array_the_same); i++)
        printf("%dth character of second array:\t%c\n", i+1, char_array_the_same[i]);
    printf("-----------------------------\n");

    //TODO:
    // What is the difference between the arrays?
    printf("A masodik megadasnal van egy maradek karakter\n");
    printf("(egy enter) ami mutatja a karakterlanc veget.\n");
    printf("Ezert eggyel tobb elemu a masodik megadas\n");
    return 0;
}
