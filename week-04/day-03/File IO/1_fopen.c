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

    for(int i = 0; i < 200; i++) {
        fprintf(valami, "Szia!\n");
    }
    //�gy is lehet:
    fputs("Szia!", valami);

    fclose(valami);
    //be kell z�rni!


    return 0;


}

