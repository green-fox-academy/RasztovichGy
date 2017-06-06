#include <stdio.h>
#include <math.h>

// This program should work correctly with the following input: 20, 400

float main()
{
	float number, result;
	printf("Please enter a number: ");
	//fflush(stdin);
	scanf("%f", &number);

	printf("Please enter the square of that number: ");
	//fflush(stdin);
	scanf("%f", &result);

	if (powf(number, 2) == result) {
		printf(":)\n");
	} else {
		printf(":(\n");
    }
	return 0;
}

/* int-re se jó.
2 és 4-re működik. 16^2=256-ra is jó. talán a pow függvény nem tudja kezelni? ez a gond!
powf függvényt kell alkalmazni, az tudja kezelni ezt a méretet.
jelzem, az if syntaxa csúnyácska volt, nem is tudom kell-e a zárójelnyitásokkal figurázni,
de hát a linux sztájlgájd mégiscsak, na.
az az fflush fgv meg fogalmam sincs mi, de nem érzem szükségét.
*/
