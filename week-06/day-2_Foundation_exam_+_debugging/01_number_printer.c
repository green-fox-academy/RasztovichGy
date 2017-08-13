#include <stdio.h>
#include <stdint.h>

void print_numbers(int64_t from, int64_t to)
{
	for (int64_t i = from; i < to; i++)
		printf("%lli\t", i);
}

int main()
{
	print_numbers(2147483600, 2147484600);
	return 0;
}

/* a hiba az volt, hogy %d csak int terjedelemben tud kiírni eredményt,
 * a megadott számok pont az int32 tartományán kívül voltak, ezért marhaságot adott szegényem.
 * /de int main() maradhat, a függvény is lehet void.
 azaz: from, to, i legyen int_64_t és a printf szintaxa pedig %lli (longlongint)
 * ja meg még el is volt gépelve a printf parancs és print függvénynév a main-ben
 * ja meg \n csak 295 sort tördelt ezért nem from-tól indult a kiírás. \t már oké
 */
