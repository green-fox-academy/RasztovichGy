#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#DEFINE MAX_COMMAND_LEN 255
#DEFINE COM_ADD "add"
#define COM_LIST "list"
#define COM_EXIT "exit"
#define COM_WRITE "write"

incomplete!!!!!!!!!!!!

int main()
{

    book_storage_t storage;
    book_init(&storage);

        char com[MAX_COMMAND_LEN];
        char com_to_parse[MAX_COMMAND_LEN];

        while (1) {
            gets(com);
            strcpy(com_to_parse, com);
            char *p;
            p = strtok(com_to_parse, "\"");

            // get tilte
            if(strstr(p, COM_ADD)) {
                p = strtok(NULL, "\"");
                char title[BOOK_TITLE_MAX_LEN];
                strcpy(title, p);
             // get author
                p = strtok(NULL, "\"");
                p = strtok(NULL, "\"");
                char author[BOOK_AUTHOR_MAX_LEN];
                strcpy(author, p);
             // get year
                p = strtok(NULL, "\"");
                int year = atoi(p);
            // get state
                p = strtok(NULL, "\"");
                p = strtok(NULL, "\"");
                state_t state;
                if (strcmp(p, "e")) == 0)
                    state = STATE_EXCELLENT;
                else
                    state = STATE_BAD;


             //add sstuff
             book_add(&storage, title, author, year, state, theme);
                else if (strstr)


               //get file

               stb...



            }
        }
   book
    return 0;
}
