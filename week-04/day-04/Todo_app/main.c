#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "todo.h"

#define MAX_COMMAND_LEN 100
#define MAX_FILE_NAME_LEN 100
#define COM_ADD "-a"
#define COM_LIST "-l"
#define COM_EXIT "exit"
#define COM_WRITE "-wr"
#define COM_READ "-rd"

//main menu
int main()
{
    printf("\nWelcome to main menu of Todo app!\n");
    printf("\nInstead of playing with this midget\nyou should start work.\n\n");

    printf("Todo application\n");
    printf("===================\n");
    printf("Commands:\n");
    printf("-a\tAdds a new task\n");
    printf("-wr\tWrite current todos to file\n");
    printf("-rd\tRead todos from a file\n");
    printf("-l\tLists all the tasks by adding a number\n");
    printf("-e\tEmpty the list\n");
   // printf("-r\tRemoves a task\n");
   // printf("-c\tCompletes a task\n");
   // printf("-p\tAdd priority to a task\n");
   // printf("-lp\tLists all the tasks by priority\n");

    printf("\nPlease choose one action.\n");

    //init functions
    task_storage_t storage;
    todo_init(&storage);

    //user input beolvasás
    char com[MAX_COMMAND_LEN];
    char com_to_parse[MAX_COMMAND_LEN];
    while (1) {
        gets(com);
        strcpy(com_to_parse, com);
        char *p;
        p = strtok(com_to_parse, "\"");

        if(strstr(p, COM_ADD)) {    //ha a választás "-a"
            p = strtok(NULL, "\"");
            char task[TODO_TASK_MAX_LEN];
            strcpy(task, p);

            // Status beolvas
            p = strtok(NULL, "\"");
            status_t status;
            if (strcmp(p, "done") == 0)
                status = STATUS_DONE;
            else if (strcmp(p, "in_progress") == 0)
                status = STATUS_IN_PROGRESS;
            else if (strcmp(p, "pending") == 0)
                status = STATUS_PENDING;
            else
                status = STATUS_WAIT_TO_START;

            // Priority beolvas
            p = strtok(NULL, "\"");
            prior_t priority;
            if (strcmp(p, "must") == 0)
                priority = PRIOR_MUST;
            else if (strcmp(p, "primary") == 0)
                priority = PRIOR_PRIMARY;
            else if (strcmp(p, "secondary") == 0)
                priority = PRIOR_SECONDARY;
            else
                priority = PRIOR_CAN_WAIT;

            // további juzer inputok
            task_add(&storage, task, status, priority);
        } else if (strstr(p, COM_LIST)) {           //"-l"
            task_list(&storage);                    // task list függvény meghívása
        } else if (strstr(p, COM_EXIT)) {           //"exit"
            break;
        } else if (strstr(p, COM_WRITE)) {          //"wr"
            // fájlnév bekérés
            p = strtok(NULL, "\"");
            char path[MAX_FILE_NAME_LEN];
            strcpy(path, p);
            // fájlba írás függvény meghívása
            task_write(&storage, path);
        } else if (strstr(p, COM_READ)) {
            // fájlnév bekérés
            p = strtok(NULL, "\"");
            char path[MAX_FILE_NAME_LEN];
            strcpy(path, p);
            // fájlból beolvasás függvény meghívása
            task_read(&storage, path);
        }
    }
    todo_deinit(&storage);

    return 0;
}
