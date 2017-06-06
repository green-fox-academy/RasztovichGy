#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
TODO: Implement a function that concatenates 2 strings (dest and source).
The return value should be the concatenated strings.
*/

char *totorocat(char *destination, const char *source)
{
   int i;
   for (i = 0; destination[i] != '\0'; i++) {
     //   printf("%d\n", i);
   }
   int j;
   for (j = 0; source[j] != '\0'; j++) {
        destination[i + j] = source[j];
   }
   //printf("%d\n", i);
   destination[i + j] = '\0';
   return destination;
}

int main()
{
    char dest[100] = "Kis ";
    puts(totorocat(dest, "kutya\n"));
    return 0;
}
