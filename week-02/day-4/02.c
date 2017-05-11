#include <stdio.h>

int main() {
    char char_array[] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";

	//TODO:
    // Print out the two arrays character-by-character
    for(int i=0; i<4 ; i++){
        printf("char_array %c\n", char_array[i]);
    }

    printf("----------------------\n");

    for(int i=0; i<4 ; i++){
        printf("char_array_the_same %c\n", char_array_the_same[i]);
    }
	//TODO:
    // What is the difference between the arrays?
    printf("\n\nWhat is the difference between the arrays?\n");
    printf("char_array_the_same as char: %c\n", char_array_the_same);
    printf("char_array_the_same as dec num: %d\n", char_array_the_same);
    printf("char_array_the_same as string: %s\n", char_array_the_same);

    return 0;
}
