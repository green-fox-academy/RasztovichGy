#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

/***********************
* Constant definitaions*
************************/


incomplete!!!!!!!!!!!!




#define BOOK_TITLE_MAX_LEN 255
#define BOOK_AUTHOR_MAX_LEN 255
/*
Kazy A/C
antikvárium adatbázis!

1. add "title" "author" "year" "e/g/b" "lit/sci/sci-fi/misc"
2. list
3. save file
4. load file
5. delete

*/


typedef enum state {
    STATE_EXCELLENT,
    STATE_GOOD,
    STATE_BAD
}state_t;

typedef enum theme {
    THEME_LITERATURE,
    THEME_SCIENCE
    THEME_SCI_FI
    THEME_MISC
}theme_t;

typedef struct {
    char title[BOOK_TITLE_MAX_LEN];
    char author[BOOK_AUTHOR_MAX_LEN];
    int year;
    sótate_t state;
    theme_t theme;
}book_t;

typedef struct {
    book_t *arr;
    unsigned int length;
}book_storage_t;


/******************
* Global variables*
*******************/
book_storage_t storage;


/***********************
* Function declarations*
************************/
void...
innen sok hiányzik




#endif // BOOK_H_INCLUDED
