//Create a client app that ping the google.com to get than latency, and print it out.
#include <stdio.h>      // printf
#include <stdlib.h>     // system
//#include <winsock2.h> // in this task this declaration file is not needed to include
#include <string.h>     // strcat


int main ()
{
    /*char command[50];
    char option[50];
    printf("Type a dos command\n");
    scanf("%s", command);
    printf("Add command option\n");
    scanf("%s", option);*/ //I tried to merge the dos command and its option but it didnt work...

    char command[50] = "ping"; //input dos command name
    char option[50] = " -n 5"; //input command option. Type space before the option!
    char target_name[50] = " google.com"; //input target name
    system(strcat((strcat(command, option)), target_name)); //call dos command
    //dospromptcommand = system(strcat((strcat(command, option)), target_name)); //it is useless to store the value in an int var
    //printf("%d\n", dospromptcommand); //useless, only returns 0
    return 0;
}


