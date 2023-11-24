
#define STACK_SIZE  10

#define NULLPTR ((void*)0)

typedef struct
{
    int size;
    int sp;
    int *dataArr;

} stack_t;

typedef enum
{
    STACK_FULL,
    STACK_EMPTY,
    STACK_DONE

} stackStatus_t;



typedef stack_t* STACK_T;


STACK_T stack_create(int size);

void stack_delete(stack_t** st);

stackStatus_t stack_push_dynamic(stack_t *st,int data);


stackStatus_t push(int data);

stackStatus_t pop(int *pdata);



/***********by using Linked List************************************/
typedef struct node_stack
{

    int data;

    struct node_stack* next;
    struct node_stack* prev;

} stack_node;

typedef struct stack_LL
{
    int size;

    struct node_stack *head;
    struct node_stack *tail;

} stack_t_LL;



stack_t_LL* create_Stack_LinkedList(void);

stack_node* create_StackNode(int data);


stackStatus_t stack_push_LL(stack_t_LL *list,int Data );

stackStatus_t stack_pop_LL(stack_t_LL*list,int *poped_Data);
