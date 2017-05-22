#include <stdio.h>
#include <stdlib.h>

// Write a program that asks for two numbers
// The first number represents the number of girls that comes to a party, the
// second the boys.

// It should print "The party is excellent!" if the the number of girls and
// boys are equal and there are more people coming than 20

// It should print "Quite cool party!"
// if there are more than 20 people coming but the girl - boy ratio is not 1-1

// It should print: "Average party..."
// if there are less people coming than 20

// It should print: "Sausage party"
// if no girls are coming, regardless the count of the people

int girls;
int boys;

int main(){
    printf("Add the number of girls\n");
    scanf("%d",&girls);
    printf("Add the number of boys\n");
    scanf("%d",&boys);

    if(girls==0){
        printf("Sausage party");
    } else if(girls==boys && (girls+boys)>20){
        printf("The party is excellent!");
    } else if((girls+boys)>20){
        printf("Quite cool party!");
    } else {
    printf("Average party...");
    }
return 0;
}







