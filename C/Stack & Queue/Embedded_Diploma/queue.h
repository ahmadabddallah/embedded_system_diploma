#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#define QUEUE_SIZE  3

typedef enum{
QUEUE_DONE,
QUEUE_FULL,
QUEUE_EMPTY

}queueState_t;


queueState_t dequeue(int *data);

queueState_t enqueue(int data);

void print_all_queue(void);
