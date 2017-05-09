#include <stdio.h>
#include <stdint.h>

int main() {
	int a = 654;
	uint64_t b = 654987543;
	// Tell if the reminder of b divided by a is 3
	uint64_t aa = (uint64_t) a;

    if(b%aa == 3){
        printf("b/a maradeka 3\n");
    }

	return 0;
}
