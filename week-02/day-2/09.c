#include <stdio.h>

int main() {
	int i = 53624;
	// tell if it has 11 as a divisor
	if (i%11 == 0) {
        printf("a 11 osztoja az 53625-nek");
	}
    else {
        printf("a 11 nem osztoja az 53625-nek");
    }
	return 0;
}
