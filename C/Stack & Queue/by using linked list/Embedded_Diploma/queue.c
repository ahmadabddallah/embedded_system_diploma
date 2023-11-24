#include"queue.h"

static int queue[QUEUE_SIZE];
static int tmp_queue[QUEUE_SIZE+1];
static int qp=0;
/*private function for me*/
static void dequeue_arrange();



queueState_t dequeue(int *data)
{

    queueState_t state=QUEUE_DONE;
    if(qp>0)
    {
        *data=queue[0];
        dequeue_arrange();
        qp--;
        printf("qp=%d\n",qp);
    }
    else
    {
        state=QUEUE_EMPTY;
    }
    return state;

}

queueState_t enqueue(int data)
{

    queueState_t state=QUEUE_DONE;
    printf("qp=%d\n",qp);
    if(qp<QUEUE_SIZE)
    {
        queue[qp]=data;
        qp++;
    }
    else
    {
        state=QUEUE_FULL;
    }
    return state;

}

static void dequeue_arrange()
{
    for(int i=0;i<qp;i++){
        tmp_queue[i]=queue[i];
    }

    for(int i=0;i<qp-1;i++){
        queue[i]=queue[i+1];
    }

}




void print_all_queue(void){
    for(int i=0;i<qp;i++){
        printf("queue[%d]=%d\n",i,queue[i]);
    }
}


/***********by using Linked List************************************/



queue_t_LL* create_Queue_LinkedList(void){

    queue_t_LL* newQueue=malloc(sizeof(queue_t_LL));

    newQueue->size=0;
    newQueue->head=NULLPTR;
    newQueue->tail=NULLPTR;

    return newQueue;


}

queue_node* create_QueueNode(int data){
    queue_node* newNode=malloc(sizeof(queue_node));
    if(newNode==NULLPTR){
        //stack is FULL
        return 0;
    }
    newNode->next=NULLPTR;
    newNode->prev=NULLPTR;
    newNode->data=data;

    return newNode;

}


queueState_t queue_enqueue_LL(queue_t_LL *list,int Data ){
     queue_node* newNode=malloc(sizeof(queue_node));
     if(newNode==NULLPTR){
        return QUEUE_FULL;
     }
     newNode->data=Data;
    if(list->size==0){
        //queue is empty
        list->tail=newNode;
        list->head=newNode;
    }
    else{
        newNode->prev=list->tail;
        list->tail->next=newNode;
        list->tail=newNode;
    }
    list->size++;



}

queueState_t queue_dequeue_LL(queue_t_LL*list,int *poped_Data){

    queue_node* tmpNode=malloc(sizeof(queue_node));
    tmpNode=list->head;
    if(list->size==0){
        return QUEUE_FULL;
    }
    if(list->size==1){
        *poped_Data=list->head->data;
        list->head=NULLPTR;
        list->tail=NULLPTR;
        free(tmpNode);
    }
    else{
         *poped_Data=list->head->data;
          list->head->next->prev=NULLPTR;
         list->head=list->head->next;
         free(tmpNode);
    }

    list->size--;


}
