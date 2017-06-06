#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "todo.h"

//memóriában helyfoglalás a teljes todo appnak
void todo_init(task_storage_t *storage)
{
    storage->arr = NULL; //a tárolót először nullázuk - memóriaszemét eliminálás
    storage->memspace = 0; //a tároló hosszát is nullázuk
}

//a program végén felszabadítjuk a befoglalt memóriát és nullázuk a tárolót is
void todo_deinit(task_storage_t *storage)
{
    free(storage->arr);
    storage->arr = NULL;
    storage->memspace = 0;
}

//definiáljuk a feladat-hozzáadó függvényt
//****************************************
//először a struktúráját
int task_add(task_storage_t *storage,
            char *task,
            status_t status,
            prior_t priority)
{
    //memoban helyfoglalas az uj feladatnak
    int memspace_new = storage->memspace + 1;
    storage->arr = realloc(storage->arr, sizeof(task_t) * memspace_new);
    storage->memspace = memspace_new;

    //Adatbeolvasas
    //majd úgy kell megadni egy új feladatot hogy
    //"feladat_leirasa" "wts/in_progress/p/done" "m/p/s/cw"
    // a 0. hely a sorszám lesz! az 1. adat a task, a 2. a status a 3. a prioritás.
    strcpy(storage->arr[memspace_new - 1].task, task);
    storage->arr[memspace_new - 1].status = status;
    storage->arr[memspace_new - 1].priority = priority;

    return 0;
}

//definiáljuk a feladat-kilistázó függvényt
//*****************************************
int task_list(task_storage_t *storage)
{
    if (storage == NULL)    //amíg nincs megadva semmilyen adat, adjon valami választ
        return -1;   //ha szöveget nem ad vissza, maradjon return -1;

    for (int i = 0; i < storage->memspace; i++) {
        printf("%d - ", i + 1);                     //feladat sorszáma
        printf("%s - ", storage->arr[i].task);      //task

        switch (storage->arr[i].status) {           //status
        case STATUS_WAIT_TO_START:
            printf("wait to start - ");
            break;
        case STATUS_IN_PROGRESS:
            printf("in progress - ");
            break;
        case STATUS_PENDING:
            printf("pending - ");
            break;
        case STATUS_DONE:
            printf("Done! - ");
            break;
        default:
            break;
        }

        switch (storage->arr[i].priority) {            //priority
        case PRIOR_MUST:
            printf("Must do!");
            break;
        case PRIOR_PRIMARY:
            printf("primary");
            break;
        case PRIOR_SECONDARY:
            printf("secondary");
            break;
        default:
            printf("can wait");
            break;
        }
        printf("\n");                               //végül egy sortörés
    }
    return 0;
}

//definiáljuk a fájlba író függvényt
//**********************************
int task_write(task_storage_t *storage, char *path)
{
    if (storage == NULL || path == NULL)    //ha nincs beadott adat vagy nincs megadott fájl elérési út, adjon valami választ
        return -1;

    FILE *file = fopen(path, "w");  //különben nyisson egy fájlt fopen paramétere "w"!
    if (file == NULL)   //hm. kell-e ez?
        return -1;
    for (int i = 0; i < storage->memspace; i++) {
        fprintf(file,
                "%s %d %d\n",              //note: enum sorai egy-egy számként vannak tárolva
                storage->arr[i].task,
                storage->arr[i].status,
                storage->arr[i].priority);
    }

    fclose(file);
    return 0;
}


//definiáljuk a fájlból beolvasó függvényt
//****************************************
int task_read(task_storage_t *storage, char *path)
{
    if (storage == NULL || path == NULL)    //ha nincs beadott adat vagy nincs megadott fájl elérési út, adjon valami választ
        return -1;

    FILE *file = fopen(path, "r");  //különben nyissa meg a fájlt -> fopen paramétere "r"!
    if (file == NULL)               //ha  afájl üres, jöjjön vissza -1 üzenettel.
        return -1;

    //a struktura, amit be kell olvasni:
    char task[TODO_TASK_MAX_LEN];
    status_t status;
    prior_t priority;

    while(fscanf(file, "%s %d %d\n", task, &status, &priority) == 3) {
        task_add(storage, task, status, priority);
    }

    fclose(file);
    return 0;
}

//definiáljuk a listaürítő függvényt
//****************************************
/*int task_emptylist(task_storage_t *storage);
{
    storage->NULL;
    return 0;
}
*/
