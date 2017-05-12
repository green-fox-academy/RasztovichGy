#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Create a function named create palindrome following your current language's style guide.
It should take a string, create a palindrome from it and then return it.
*/


int main()
 {

    char word[255];

    printf("Type a word\n");
    scanf("%s", word);

    char* drow=strrev(word);

    printf("%s", word);

    return 0;


}

