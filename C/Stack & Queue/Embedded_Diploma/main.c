#include <stdio.h>
#include <stdlib.h>

#include"string.h"
#include "math.h"

#include"stack.h"
#include"queue.h"

int main()
{

    int x,y;


    while(1){
        print_all_queue();

        printf("please enter a number to enqueue and 0 to dequeue\n ");
        scanf("%d",&x);

        if(x!=0){
            if(enqueue(x)==QUEUE_DONE){
                printf("%d is enqueued\n",x);
            }
            else{
                printf("Queue is full\n");
            }

        }
        else{
            if(dequeue(&y)==QUEUE_DONE){
                printf("%d is dequeued\n",y);

            }
            else{
                printf("Queue is Empty\n");
            }

        }

    }


    return 0;

}
