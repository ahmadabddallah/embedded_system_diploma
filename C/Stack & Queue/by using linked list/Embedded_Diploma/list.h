
#define NULLPTR ((void*)0)

typedef enum{

LIST_EMPTY,
NOT_FOUND,
LIST_DONE

}listStatus_t;

typedef struct node{

int data;

struct node *next;

}node_t;

typedef struct dnode{

int data;
struct dnode *next;
struct dnode *prev;


}dnode_t;

typedef struct{
struct dnode *head;
struct dnode *tail;
int size;

}dlist_t;

typedef dlist_t* LIST;





dlist_t* DoubleList_create(void);

node_t *createNode(int data);


void list_print(node_t* head);
void list_print_last(node_t *head);

void list_addNodeToLast(node_t**phead,int data);

void list_addNodeToFirst(node_t**phead,int data);

listStatus_t list_editNode(node_t* head,int oldData,int data);

listStatus_t list_removeData(node_t **phead,int oldData);
listStatus_t list_insertAfter(node_t *head,int prevData,int Data);
