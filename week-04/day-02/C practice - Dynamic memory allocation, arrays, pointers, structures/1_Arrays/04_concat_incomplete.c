#include <stdio.h>
#include <stdlib.h>

/*
TODO: Implement a function that concatenates 2 strings (dest and source).
The return value should be the concatenated strings.
*/

//def two strings
char string1[];
char string2[];

//def two pointers
char *dest_ptr = &string2; //a *dest_ptr mutasson a string t�mb elej�re.
char *source_ptr = &string1;

//def �sszef�z� f�ggv�ny defini�l�sa
/* char *string_concat(char *dest_ptr, char *source_ptr)
{
    for(int i=0; dest[i]!='\0'; i++) {
        ;
}
*/
int main()
{
//ask for j�zer input
    printf("First word: ");
    scanf("%s", string1); //pl "kis"
    printf("Second word: ");
    scanf("%s", string2); //pl "kutty"

//a memoriacimek
    printf("dest ptr memcime: %x\n", *dest_ptr);
    printf("src ptr memcime: %x\n", *source_ptr);

//pointerek haszn�lat�val
    printf("dest ptr erteke: %c\n", *dest_ptr); //u
    printf("src ptr erteke: %c\n", *source_ptr); //k

    char *concatenated = string_concat(string1, string2);


    return 0;
}
