#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#define QUEUE_SIZE  3

#define NULLPTR ((void*)0)

typedef enum{
QUEUE_DONE,
QUEUE_FULL,
QUEUE_EMPTY

}queueState_t;


queueState_t dequeue(int *data);

queueState_t enqueue(int data);

void print_all_queue(void);



/***********by using Linked List************************************/
typedef struct node_queue
{

    int data;

    struct node_queue* next;
    struct node_queue* prev;

} queue_node;

typedef struct queue_LL
{
    int size;

    struct node_queue *head;
    struct node_queue *tail;

} queue_t_LL;



queue_t_LL* create_Queue_LinkedList(void);

queue_node* create_QueueNode(int data);


queueState_t queue_enqueue_LL(queue_t_LL *list,int Data );

queueState_t queue_dequeue_LL(queue_t_LL*list,int *poped_Data);
