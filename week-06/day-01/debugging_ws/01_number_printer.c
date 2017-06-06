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

/* a hiba az volt, hogy %d csak int terjedelemben tud ki�rni eredm�nyt,
 * a megadott sz�mok pont az int32 tartom�ny�n k�v�l voltak, ez�rt marhas�got adott szeg�nyem.
 * /de int main() maradhat, a f�ggv�ny is lehet void.
 azaz: from, to, i legyen int_64_t �s a printf szintaxa pedig %lli (longlongint)
 * ja meg m�g el is volt g�pelve a printf parancs �s print f�ggv�nyn�v a main-ben
 * ja meg \n csak 295 sort t�rdelt ez�rt nem from-t�l indult a ki�r�s. \t m�r ok�
 */
