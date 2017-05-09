#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t x = 0b11001100;
    uint8_t y = 0b01010101;
	uint8_t z = 0b0;

	// Be z equal to the bitwise and of x and y
	// Check the result with printf
    printf("\n");
    printf("// Be z equal to the bitwise and of x and y\n");
    printf("// Check the result with printf\n");
    printf("-------------------------------\n");
    z = x & y;
    printf("%d", z);

	// Be z equal to the bitwise or of x and y
	// Check the result with printf
	printf("\n");
    printf("// Be z equal to the bitwise or of x and y\n");
    printf("// Check the result with printf\n");
    printf("-------------------------------\n");
    z = x | y;
    printf("%d\n", z);

    return 0;
}
