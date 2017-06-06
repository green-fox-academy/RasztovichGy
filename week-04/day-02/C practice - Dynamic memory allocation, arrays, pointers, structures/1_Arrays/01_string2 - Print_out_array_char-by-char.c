#include <stdio.h>

int main()
{
    char my_name_array[] = "My Nameee";

	//TODO:
    // Print out the array character-by-character

	printf("Teljes tomb merete byte-ban: %d\n", sizeof(my_name_array)); //teljes tömb mérete

	printf("%s\n", my_name_array); //ezzel simán kiírja egy sorba hogy My Name - note: %s tipus!

    printf("%d\n", sizeof(my_name_array[3]));  //egy betû a tömbben 1 byte méretû
    printf("%d\n", my_name_array[0]); //the first char of array in decimal = 77, which is M
    printf("%d\n", my_name_array[1]);
    printf("%d\n", my_name_array[2]);
    printf("%d\n", my_name_array[3]);
    printf("%d\n", my_name_array[4]);

	int n = sizeof(my_name_array)/sizeof(my_name_array[0]); //ez a for is egy sorba írja ki
	for(int i=0; i<n; i++) {
		printf("%c", my_name_array[i]);
	}

	printf("\n---------------------\n");
    for (int i = 0; i < (sizeof(my_name_array) / sizeof(my_name_array[0])); i++)
       // printf("%c", my_name_array[i]); //ez egymás mellé, folytonosan írja ki a betuket
        printf("%dth character:\t%c\n", i+1, my_name_array[i]); //ez meg egymás alá írja ki a betuket

    return 0;
}
