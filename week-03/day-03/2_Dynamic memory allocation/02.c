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
    scanf("%d",&n); //'&' jel teszi be az �rt�ket a v�ltoz�ba!
    printf("\n");
    //printf("The program will calculate the average of %d numbers.\n",n);

    int* array;    //itt el�jelzem, hogy a t�mb�t majd el kell helyezni vhol a mem�ri�ban
    array=(int*) calloc(n,sizeof(int)); //itt adom meg hogy a t�mb n elem� legyen �s mem�riahelyet is foglalok hozz�. Az int*-gal jelzem, hogy a mem�ri�ban val� helyfoglal�st a t�mb elej�t�l kezdje - mintha lehetne m�sk�pp, whatev�r.

    for(int i=0;i<n;++i){   //NOTE TO SELF: for argumentumait pontos'f�ckin'vessz�vel v�lasztom el!
        printf("Please add the %dth number: %t", i+1);
        scanf("%d",&array[i]); //az i-edik, j�zer �ltal megadott sz�mot bevessz�k a t�mb i-edik elem�nek
        sum=sum+array[i]; //a sum v�ltoz� null�val kezd - ez�rt defini�lom legfel�l, nehogy memszem�t legyen a kezd��rt�ke. ez a kifejt�s r�vid�thet� sum+=array[i]-vel is.
    }

    float avg=(float)sum/n; //NOTE TO SELF: k�t integerb�l CSAK integer eredm�nyt k�pes adni, hi�ba az eredm�nyv�ltoz� float t�pus�. Ez�rt a sz�ml�l�t �talak�tjuk float t�pus�v�. Gondolom ezen �talak�t�s elhagyhat�, ha eleve a sum-ot float-k�nt defini�lom (merthogy �gyis le kell majd osztani).
    printf("---------------------------------");
    printf("\nThe average of %d numbers: %.3f\n",n,avg);

    free(array); //mem�ria felszabad�t�s!
    return 0;
}

//de j� lenne t�rdelni a hossz� megjegyz�seimet!
