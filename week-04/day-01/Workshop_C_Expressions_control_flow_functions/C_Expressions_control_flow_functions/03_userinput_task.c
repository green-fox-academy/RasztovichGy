#include <stdio.h>
#include <stdlib.h>

/*
Create a program which ask for a name and an age.
From the age it tells the user when he or she will be 100 years old.
You should only take care of the years (don't bother with the months or days).
*/

int age;
char name[255];

int main() {
    printf("What's your name?\n");
    gets(name);
    printf("How old are you?\n");
    scanf("%d",&age);

    printf("%s, you will be 100 years old in the year %d.\n", name, wwybh(name,age));

    return 0;
}

int wwybh(name,age){
    return 2017+100-age;
    }
