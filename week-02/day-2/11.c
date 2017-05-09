#include <stdio.h>

int main() {
	int k = 1522;
	// tell if k is dividable by 3 or 5

	if (k%3 == 0 || k%5 == 0) {
        printf("k oszthato 3-mal vagy 5-tel");
	}
    else {
        printf("k NEM oszthato 3-mal vagy 5-tel");
    }

	return 0;
}
