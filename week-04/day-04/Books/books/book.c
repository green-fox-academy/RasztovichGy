#include <book.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void book_init()
{
    storage.arr = NULL;
    storage.length = 0;
}

void book_deinit()
{
    free(storage)
    storage.arr =  stbstbsbtbstbsbtbsbt


}


it book_add(book_storage_t *storage,
            char *title,
            char *-author,
            int year,
            state_t state,
            theme_t theme)
{
    // -.-.-    hossza 3
    //-.-.-.x   hossza 4
    //0.1.2.3 index
    // Allocate new space for a book
    int new_length = storage->length + 1;
    storage->arr = realloc(storage->arr, sizeof(book_t) * new_length);
    storage->length = new_length;

    // Fill in data into the new book
    strcpy(storage->arr[new_length - 1].title, title);
    strcpy(storage->arr[new_length - 1].author, author);
    storage->arr[new_length - 1].year = year;
    storage->arr[new_length - 1].state = state;
    storage->arr[new_length - 1].theme = theme;


    return 0;
}


int list(book_storage_t *storage)
{

    if(storage == NULL)
        return -1;

    for(int i =0; i < storage->length; i++) {
        printf("%d - ", i+1);
        printf("%s - ", storage->arr[i].title);
        printf("%s - ", storage->arr[i].author);
        printf("%s - ", storage->arr[i].year);

    switch (storage->arr[i].state) {
    case STATE_EXCELLENT:
        printf("excellent - "};
        break;
    case STATE_BAD:
        printf("bad - "};
        break;
    case STATE_FOSCSI:
        printf("foscsi - "};
        break;
    default:
        break;

   switch (storage->arr[i].state) {
    case THEME_SCIENCE:
        printf(" - "};
        break;
    default:
        break;

    }

    return 0;
}

int book_write(book_storage_t *storage, char *path) {
    if (storage == NULL || path == NULL)
        return -1;
    FILE *file = fopen(path, "w");
    if (file == NULL)
        return -1;

    book_t book;
    while(fscanf(file,
                "%s %s %d %d %d"\n,
                book.author,
                book->arr[i].title,
                book->arr[i].year,
                book->arr[i].state,
                book->arr[i].theme,
    fclose(file);
}




incomplete!!!!!!!!!!!!
