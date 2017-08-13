#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



/** TODO:
 * Create a function called "range" that creates a new array and returns a pointer to it.
 * It should fill the array with numbers based on it's parameters.
 * It should take 3 parameters:
     * int from: the first number in the array
     * int to: it will fill the array till it would reach this number (so this number is not in the array)
     * int step: the step between the numbers
 *
 * Examples:
 * range(0, 10, 2) -> {0, 2, 4, 6, 8}
 * range(1, -8, -3) -> {1, -2, -5}
 *
 * It should delete any dynamically allocated resource before the program exits.
 **/

//hint1: http://www.w3schools.in/c-tutorial/functions/
//hint2: http://www.studytonight.com/c/user-defined-functions-in-c.php

// 1. function declaration
// dataType functionName (Parameter List)
int32_t Range(int32_t a, int32_t b, int32_t c); //int32_t eredményt adjon, a paraméterei: a, b, c lesznek és minden paramétere int32_t
                        // note: int32_t = -2^32/2....2^32




int main() {

    int32_t Range(int32_t a, int32_t b, int32_t c);

    printf("\nSa'la'la'!");
    return 0;
}

// 2. function definition
//returnType functionName(Function arguments){
//  body of the function
//}

int32_t Range(int32_t a, int32_t b, int32_t c){
    printf("Please add the start value the ceiling value and the difference!\n");
    //scanf("%d %d %d",&a,&b,&c); //beolvassa a júzer által megadott adatokat
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    printf("%d, %d, %d",a,b,c); //check hogy bevette-e a program az adatokat
    return 0;
}



