#include <stdio.h>

/*
Kazy reggeli ezmegaz 170524 FILE I/O téma
*/

int main()
{
    //syntax így néz ki:
    //FILE *fopen( const char * filename, const char * mode );
    //ezzel létrehozok egy ptr-t arra a fájlra

    //a gyakorlatban:
    FILE *valami = fopen("totoro.txt", "w+");
    //létre kell hozni egy változót, ami pointer!


    char buffer[256];

    while(fgets(buffer, 256, valami) != NULL) { //ha
        buffer[strlen(buffer) - 1] = '\0';
        puts(buffer);
    }

    //fgets(buffer, 256, valami);

    fclose(valami);
    //be kell zárni!

    return 0;

}

