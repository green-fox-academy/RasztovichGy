#include <stdio.h>

int main() {
    char my_name_array[] = "Rasztovich Gyula";

	//TODO:
    // Print out the array character-by-character

    for(int i=0; i<16 ; i++){
            printf("A nevem %d. betuje: \t %c\n", i+1, my_name_array[i]);
    }
    return 0;
}
