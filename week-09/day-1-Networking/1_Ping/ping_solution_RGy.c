//Create a client app that ping the google.com to get than latency, and print it out.
#include <stdio.h>      // printf
#include <stdlib.h>     // system
//#include <winsock2.h>
#include <string.h>     //strcat


int main ()
{
    /*char command[50];
    char option[50];
    printf("Type a dos command\n");
    scanf("%s", command);
    printf("Add command option\n");
    scanf("%s", option);*/ //I tried to merge the dos command and its option but it didnt work...

    char command[50] = "ping";
    char option[50] = " -n 5";
    char target_name[50] = " google.com";
    int dospromptcommand = system(strcat((strcat(command, option)), target_name));

    //printf("%d.\n", dospromptcommand);
    return 0;
}

