#include <stdio.h>
#include <stdlib.h>

int main() {
    int* pointer = NULL;

    // TODO:
    // Please allocate a 5 long array and fill it with numbers from 0 to 4, then print the whole array
    int array[5] = {0,1,2,3,4};
    int i;

    int* ptr_array = (int*) calloc(5,sizeof(int));

    for(i=0; i<5; i++) {
        printf("The %dth element of the array is: %d\n",i+1,array[i]);
    }

    // Please delete the array before the program exits
    free(ptr_array);
    return 0;
}
