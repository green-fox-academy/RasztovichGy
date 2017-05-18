#include <stdio.h>
#include <stdint.h>

// TODO:
// Please create a program that asks for a count when it starts.
// It should ask for a number count times, then it should print the average of the numbers.
// It should delete any dynamically allocated resource before the program exits.

int main() {
    int n;
    int sum=0;

    printf("How many numbers do you want to average?\n");
    scanf("%d",&n); //'&' jel teszi be az értéket a változóba!
    printf("\n");
    //printf("The program will calculate the average of %d numbers.\n",n);

    int* array;    //itt elõjelzem, hogy a tömböt majd el kell helyezni vhol a memóriában
    array=(int*) calloc(n,sizeof(int)); //itt adom meg hogy a tömb n elemû legyen és memóriahelyet is foglalok hozzá. Az int*-gal jelzem, hogy a memóriában való helyfoglalást a tömb elejétõl kezdje - mintha lehetne másképp, whatevör.

    for(int i=0;i<n;++i){   //NOTE TO SELF: for argumentumait pontos'fáckin'vesszõvel választom el!
        printf("Please add the %dth number: %t", i+1);
        scanf("%d",&array[i]); //az i-edik, júzer által megadott számot bevesszük a tömb i-edik elemének
        sum=sum+array[i]; //a sum változó nullával kezd - ezért definiálom legfelül, nehogy memszemét legyen a kezdõértéke. ez a kifejtés rövidíthetõ sum+=array[i]-vel is.
    }

    float avg=(float)sum/n; //NOTE TO SELF: két integerbõl CSAK integer eredményt képes adni, hiába az eredményváltozó float típusú. Ezért a számlálót átalakítjuk float típusúvá. Gondolom ezen átalakítás elhagyható, ha eleve a sum-ot float-ként definiálom (merthogy úgyis le kell majd osztani).
    printf("---------------------------------");
    printf("\nThe average of %d numbers: %.3f\n",n,avg);

    free(array); //memória felszabadítás!
    return 0;
}

//de jó lenne tördelni a hosszú megjegyzéseimet!
