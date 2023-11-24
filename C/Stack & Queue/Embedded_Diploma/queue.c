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