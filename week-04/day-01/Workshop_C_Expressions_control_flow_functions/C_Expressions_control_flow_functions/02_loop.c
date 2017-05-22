#include <stdio.h>
#include <stdlib.h>

/*
Create a program which writes down the following sentence 100 times:
"I won't cheat on the test!"
Do it with:
    - for loop
    - while loop
    - do while loop
Also create a funtion which does the same.
*/
int N;

int main() {
    printf("How much times do I want to note myself?\n");
    scanf("%d",&N);

    printf("----------------------------------\n");
    printf(" First solve the task by FOR loop \n");
    printf("----------------------------------\n");
    for (int i=0;i<N;i=i+1){ //irhatok i++-t is!;for argumentuma ;-vel van elválasztva! argumentum: kezdõérték, feltételig, növekmény, majd {}
        printf("%d.\tI won't cheat on the test!\n", i+1);
    }

    printf("----------------------------------\n");
    printf(" Now solve the task by WHILE loop \n");
    printf("----------------------------------\n");

    int j=0;
    while(j<N){
        printf("%d.\tI won't cheat on the test!\n", j+1);
        j=j+1;
    }


    printf("-------------------------------------\n");
    printf(" Now solve the task by DO WHILE loop \n");
    printf("-------------------------------------\n");

    int k=0;
    do{
        printf("%d.\tI won't cheat on the test!\n", k+1);
        k=k+1;
    }while(k<N);

    return 0;
}
