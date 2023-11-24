#include <stdio.h>
#include <stdlib.h>

#include"string.h"
#include "math.h"

#include"stack.h"
#include"queue.h"

#include "list.h"
int main(){

    int y=0;
    queue_t_LL *queue1;
    queue1=create_Queue_LinkedList();

    queue_enqueue_LL(queue1,1);
    queue_enqueue_LL(queue1,2);
    queue_dequeue_LL(queue1,&y);
     printf("y=%d\n",y);
     queue_dequeue_LL(queue1,&y);
    printf("y=%d\n",y);
    queue_enqueue_LL(queue1,1);
     queue_dequeue_LL(queue1,&y);
     printf("y=%d\n",y);
   // printf("%d",queue1->tail->data);

    /*stack_t_LL *stack1;
    stack1=create_Stack_LinkedList();
    stack_push_LL(stack1,1);
    stack_push_LL(stack1,2);
    stack_push_LL(stack1,3);
    stack_push_LL(stack1,4);

    int y;

   printf("%d\n",stack1->tail->data);

    */


    //printf("%d\n",stack1->tail->data);

    /*node_t *list1=0;
    list1=createNode(3);
    list1->next=createNode(7);
    list1->next->next=createNode(17);
    list1->next->next->next=createNode(70);

   // list_removeData(&list1,3);
  //  list_removeData(&list1,70);
  list_insertAfter(list1,3,-1);
   list_print(list1);
 //   list_print_last(list1);
/*
    STACK_T s1,s2,s_can,s_LIN;

    s1=stack_create(50);

    stack_push_dynamic(s1,1);


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
*/

}
