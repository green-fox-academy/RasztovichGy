#ifndef TODO_H_INCLUDED
#define TODO_H_INCLUDED

/** Constant def
****************/
#define TODO_TASK_MAX_LEN 255


 /** Type def
 ************/
/*note!
 enum are always assigned an integer numerical equivalent internally,
 to which they can be implicitly converted to or from.
 the integer value equivalent to the first possible value is 0,
 the equivalent to the second is 1, and so on...
 Therefore, in the data type status_t defined below,
 WAIT TO START would be equivalent to 0...
*/

/*typedef enum {
    USERINPUT_NEWTASK,
    USERINPUT_WRITETOFILE,
    USERINPUT_READFROMFILE,
    USERINPUT_LIST,
    USERINPUT_EMPTYLIST,
    USERINPUT_REMOVETASK,
    USERINPUT_CHANGESTATUS,
    USERINPUT_ADDPRIOR,
    USERINPUT_LISTBYPRIOR
}userinput_t;
*/

typedef enum {
    STATUS_DONE,
    STATUS_IN_PROGRESS,
    STATUS_PENDING,
    STATUS_WAIT_TO_START
}status_t;

typedef enum {
    PRIOR_MUST,
    PRIOR_PRIMARY,
    PRIOR_SECONDARY,
    PRIOR_CAN_WAIT
}prior_t;

typedef struct {
    char task[TODO_TASK_MAX_LEN];
    status_t status;
    prior_t priority;
}task_t;

typedef struct { //ez a pointer még nem vágom miért kell...
    task_t *arr;
    unsigned int memspace;
}task_storage_t;


 /** Function declare
 ********************/
void todo_init(task_storage_t *storage); //todo fgv-nek memfoglalas
void todo_deinit(task_storage_t *storage); //mem felszabaditas
int task_add(task_storage_t *storage, //todo listaelem hozzaadas
    char *task,
    status_t status;
    prior_t priority;);
int task_list(task_storage_t *storage); //
int task_write(task_storage_t *storage, char *path);
int task_read(task_storage_t *storage, char *path);
int task_emptylist(task_storage_t *storage, char *path);
int task_remove(task_storage_t *storage, char *path);

#endif // TODO_H_INCLUDED
