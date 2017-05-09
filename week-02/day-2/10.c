#include <stdio.h>

int main() {
	int j1 = 10;
	int j2 = 3;
	// tell if j1 is higher than j2 squared and smaller than j2 cubed

	if (j1 > j2*j2 && j1 < j2*j2*j2) {
        printf("j1 nagyobb mint j2^2 es kisebb mint j2^3");
	}
    else {
        printf("j1 NEM nagyobb mint j2^2 es NEM kisebb mint j2^3");
    }

	return 0;
}
