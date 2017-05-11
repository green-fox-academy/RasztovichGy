#include <stdio.h>

int main() {
    char buffer[255];   // Buffer variable for user input

    //TODO:
    // Get the user's name with gets
    printf("What is your name?\n");
    gets(buffer);

    //TODO:
    // Print it out with puts
    printf("Your name is: ");
    puts(buffer);
//printf("%c\n", puts(buffer));

    //TODO:
    // Get the user's pet name with getch
    char pn;
    printf("\nWhat is your pet's name?\n");
    pn=getchar();

    // char petname[255];
    // gets(petname);


    //TODO:
    // Print it out
    printf("Your pet's name is: %c\n", pn);
   // getch();
    //printf("Your pet's name is: ");
    //puts(petname);

    return 0;
}
