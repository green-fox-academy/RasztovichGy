#include <stdio.h>
#include <stdint.h>

struct bitfield {
    uint8_t boolean_value_1:1; // a kettőspont után megadjuk, hogy ezt a változót hány biten tárolja.
    uint8_t boolean_value_2:1; // értelem szerint csak 1..8 közötti szám lehet.
    uint8_t boolean_value_3:1; // a végeredmény az ezen számok összege / 8 felfele kerekítve.
    uint8_t boolean_value_4:1;
    uint8_t boolean_value_5:7;
    uint8_t boolean_value_6:1;
    uint8_t boolean_value_7:7;
    uint8_t boolean_value_8:7;
} bfs;  //elnevezem a struktúrát hogy hivatkozni lehessen rá

struct not_bitfield {           // ennek a strukturanak a merete 8 byte, hiszen a struktban 8 változó van,
    uint8_t boolean_value_1;    // aminek nincs lekorlátozva, hogy a maga bájtján hány bitet foglaljon.
    uint8_t boolean_value_2;    // azaz, egy változó 1 bájt.
    uint8_t boolean_value_3;    // ahány változó van a struktúrában, annyi bájtot foglal a memóriában.
    uint8_t boolean_value_4;
    uint8_t boolean_value_5;
    uint8_t boolean_value_6;
    uint8_t boolean_value_7;
    uint8_t boolean_value_8;
  //  uint8_t boolean_value_9;
} nbfs; //elnevezem a struktúrát hogy hivatkozni lehessen rá

int main()
{
    // TODO:
    // Print out the size of both structs (use sizeof() function)

    printf("Memory size occupied by bitfield-type structure: %d byte\n", sizeof(bfs)); //
    printf("Memory size occupied by non-bitfield-type structure: %d byte\n", sizeof(nbfs));

    return 0;
}
