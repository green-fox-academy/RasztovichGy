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

    for(int i = 0; i < 200; i++) {
        fprintf(valami, "Szia!\n");
    }
    //így is lehet:
    fputs("Szia!", valami);

    fclose(valami);
    //be kell zárni!


    return 0;


}

