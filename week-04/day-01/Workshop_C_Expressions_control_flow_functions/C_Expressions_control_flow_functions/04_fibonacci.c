#include <stdio.h>
#include <stdlib.h>

/* Write a function which is called "get_fibonacci_number". It returns the "N"th
 * Fibonacci number, where "N" is received as a parameter.
 * For example:
 *  - get_fibonacci_number(1) returns 0
 *  - get_fibonacci_number(2) returns 1
 *  - get_fibonacci_number(3) returns 1
 *  - get_fibonacci_number(4) returns 2
 *  - get_fibonacci_number(5) returns 3
 *  - get_fibonacci_number(6) returns 5
 *
 *  If the function gets invalid parameter it returns -1.
 */
 /*
Using that function create a program, which gets a number from the user, and
prints out the "N"th Fibonacci number, where "N" is the user given number.
Alert the user if he/she entered invalid value.
*/

int N;
int get_fibonacci_number(N){
    int fibo_n_minus_2=0;
    int fibo_n_minus_1=1;
    int fibo_n=0;

    if(N<1) {
        printf("You entered invalid value!\n");
        return -1;
    } else if (N==1) {
        return 0;
    } else if (N==2) {
        return 1;
    } else {
        for(int i=0; i<(N-2); i++) {
        fibo_n = fibo_n_minus_1 + fibo_n_minus_2;
        fibo_n_minus_2 = fibo_n_minus_1;
        fibo_n_minus_1 = fibo_n;
        }
        return fibo_n;
    }
}

int main(){
    printf("Which Fibonacci number would you like to get?\n");
    scanf("%d",&N);
    printf("The %dth Fibonacci number is:\t%d\n", N, get_fibonacci_number(N));

 // ha ki is kéne iratni n-ig a Fibo-együtthatókat:
 //   for(int i=0;i<N;i++) {
 //       printf("The %dth Fibonacci number is:\t%d\n", i, get_fibonacci_number(i));
 //   }
    return 0;
}
