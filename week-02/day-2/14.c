#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t number = 254;
	uint8_t result = 0;

	result = number+23;
	// Check the result with printf
    printf("%d\n", result);
 	// What happened?!
//255-on atfordult, az eredmeny ezert 21 lett mert 254+23=277-256=21

	// Try again with different datatype
	uint16_t result_16 = number+23;
	// Check the result with printf
    printf("%d\n", result_16);
	// What happened and why?
//az eredmeny 254+23=277 mert az uint_16t valtozo ertelmezesi tartomanya 16 bit azaz 0...2^16-1 = 0...65535

	//----------------------------------------
	int8_t number_negative = number;
	// Check the result with printf
    printf("%d\n", number_negative);
	// What happened and why?
//az eredmeny -2 mert int8_t 8 bites valtozo ahol elso bit az elojel es ertelmezesi tartomany -128...0...+127
// 254 az az ertelmezesi tartomanyon kivul van. A 126-dik karakternel atfordul es indul -128-rol. -128+126 = -2, ezt irta ki.
    return 0;
}
