#include <stdio.h>
#include <stdint.h>

struct computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

int main()
{
    struct computer comp = {3.2, 8, 32};

    //TODO: Change the bits to 64
    computer comp.bits = 64;
    //TODO: print out the structure members
    printf("%s\n", computer comp);
    return 0;
}
