#include <stdio.h>
#include <stdint.h>

int main() {

	uint8_t ac = 8;
	uint8_t time = 120;
	uint8_t out = 0;
	// if ac is dividable by 4
	// and time is not more than 200
	// set out to 0b100

	// if time is more than 200
	// set out to 0b010

	// otherwise set out to 0b001

	if(ac%4 == 0 & time<=200){
        out = 0b100;
        printf("%d\n", out);
    }

	else if(time>200){
        out = 0b010;
        printf("%d\n", out);
    }

	else {
        out = 0b001;
        printf("%d\n", out);
	}

	return 0;
}
