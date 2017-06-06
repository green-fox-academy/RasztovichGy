#include <stdio.h>

/*
Kazy reggeli ezmegaz 170524 FILE I/O t�ma
*/

int main()
{
    //syntax �gy n�z ki:
    //FILE *fopen( const char * filename, const char * mode );
    //ezzel l�trehozok egy ptr-t arra a f�jlra

    //a gyakorlatban:
    FILE *valami = fopen("totoro.txt", "w+");
    //l�tre kell hozni egy v�ltoz�t, ami pointer!


    char buffer[256];

    while(fgets(buffer, 256, valami) != NULL) { //ha
        buffer[strlen(buffer) - 1] = '\0';
        puts(buffer);
    }

    //fgets(buffer, 256, valami);

    fclose(valami);
    //be kell z�rni!

    return 0;

}

