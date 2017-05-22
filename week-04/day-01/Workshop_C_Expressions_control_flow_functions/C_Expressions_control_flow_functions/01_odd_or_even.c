#include <stdio.h>
#include <stdlib.h>

/*
Write a program that reads a number form the standard input,
than prints "Odd" if the number is odd, or "Even" it it is even.
*/
    int num;
    int odd_or_even(num);

int odd_or_even(num){
    if(num==0){
        printf("\nThe given number is zero which is not even nor odd.");
    } else if(num%2==0){
        printf("\nThe given number is even.");
    } else {
        printf("\nThe given number is odd.");
    }
}

int main()
{
    printf("Hello world!\n");
    printf("\nAdd a number to check!\n");
    scanf("%d",&num);
    printf(odd_or_even(num));

    printf("\nSo much wow!");
    return 0;
}

