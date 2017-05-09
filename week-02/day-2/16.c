#include <stdio.h>
#include <stdint.h>

int main() {
	uint16_t v = 424;
	// print 'Yeah!' if dividable by 4 but print 'End of program' after regardless
	if(v%4 == 0){
        printf("Yeah!\n");
    }

	return printf("End of program");
}
