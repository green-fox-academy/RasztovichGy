#include <stdio.h>

void int_to_bin_digit(int in, int count)
{

	int mask = 1U << count - 1;
	int i;
	for (i = 0; i < count; i++) {
		int result = (in & mask) ? 1 : 0;
		printf("%d", result);
		in = in << 1;
	}
}

int main()
{
	int_to_bin_digit(3, 3);
	return 0;
}

/* mi az hogy 1U? - 1U is unsigned. lényegében 1. irreleváns
1. hiba: count-1-el kell eltolni
(a mask változó egy referenciaérték lesz)
2. hiba: elgépelés a 11. sorban: in-t is el kell shiftelni 1-el.

*/
