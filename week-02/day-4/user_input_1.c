#include <stdio.h>

int main() {
    char buffer[255];   // Buffer variable for user input

    //TODO:
    // Get the user's name with scanf
    printf("Dear User, what is your name?\n");
    scanf("%s", buffer);

    //TODO:
    // Print it out with printf
    printf("Your name is: %s", buffer);

    return 0;
}
