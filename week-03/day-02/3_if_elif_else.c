#include <stdio.h>
#include <stdlib.h>

// Define the TOTORO macro which holds a number
#define TOTORO 3

int main()
{
    // Use the #if, #elif, #else macros

    // If the TOTORO macro is greater than 3 print out "Greater than 3"
    #if TOTORO > 3
            printf("\nGreater than 3");

    // If the TOTORO macro is lower than 3 print out "Lower than 3"
	 #elif TOTORO < 3
            printf("\nLower than 3");

	// Else print out "TOTORO is 3"
     #else TOTORO == 3
            printf("\nTOTORO is 3");

     #endif

    return 0;
}
