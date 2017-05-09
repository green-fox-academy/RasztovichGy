#include <stdio.h>

int main() {
	// Write a program that prints the numbers from 1 to 100.
	// But for multiples of three print "Fizz" instead of the number
	// and for the multiples of five print "Buzz".
	// For numbers which are multiples of both three and five print "FizzBuzz".

	int ag = 1;

	while (ag<=99) {
        if(ag%15==0){
        printf("FizzBuzz\n");
        }
        else if(ag%3==0){
        printf("Fizz\n");
        }
        else if(ag%5==0){
        printf("Buzz\n");
        }
        else printf("%d\n", ag);
    ag = ag+1;
    }
    	return 0;
}
