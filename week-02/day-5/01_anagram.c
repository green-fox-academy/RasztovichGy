#include <stdio.h>
#include <stdlib.h>

/*
Create a function named is anagram following your current language's style guide.
It should take two strings and return a boolean value depending on whether its an anagram or not.
*/

int main()
 {

    char word1[255];
    char word2[255];
    char temp1;
    char temp2;
    int i1;
    int j1;
    int i2;
    int j2;


    // Asking for the user's inputs
    printf("What is the first word?\n");
    gets(word1);
    printf("\nThank you. Now please add the second word.\n");
    gets(word2);

    //length of inputs
    int w1 = strlen(word1);
    int w2 = strlen(word2);

    //print users inputs just for check
//    printf("\nThe words you typed are: %s and %s.\n", word1, word2);

for (i1=0; i1<w1-1; i1++){
        for (j1=i1+1; j1<w1; j1++){
            if (word1[i1] > word1[j1]){
                temp1 = word1[i1];
                word1[i1] = word1[j1];
                word1[j1] = temp1;
            }
        }
    }
for (i2=0; i2<w2-1; i2++){
        for (j2=i2+1; j2<w2; j2++){
            if (word2[i2] > word2[j2]){
                temp2 = word2[i2];
                word2[i2] = word2[j2];
                word2[j2] = temp2;
            }
        }
    }

        if ( w1 != w2 ) {
        printf("The input's length are not the same. Inputs should contain same amount of characters.");
        }
        else {

            int igvizsg=0;

            for(int k=0; k<w1; k++){
                if(word1[k]==word2[k]){
                    igvizsg=1;
                }
                else{
                    igvizsg=0;
                }
            }

            if(igvizsg==1){
                printf("\nTrue");
                }
            else printf("\nFalse");

        }
    return 0;
}

