#include"stack.h"


static int stack[STACK_SIZE];

static int sp;


stackStatus_t push(int data){

    if(sp<STACK_SIZE)
    {
        stack[sp]=data;
        sp++;
        return STACK_DONE;
    }
    else
    {
        return STACK_FULL;
    }

}

stackStatus_t pop(int *pdata){
    stackStatus_t status=STACK_DONE;
    if(sp>0){
        sp--;
        *pdata=stack[sp];
        status= STACK_DONE;
    }
    else{
        status=STACK_EMPTY;
    }

    return status;
}


STACK_T stack_create(int size){

    stack_t *s=malloc(sizeof(stack_t));

    s->size=size;

    s->sp=0;
    s->dataArr=malloc(sizeof(int)*size);

    return s;


}


stackStatus_t stack_push_dynamic(stack_t *st,int data){

    if(st->sp<st->size){
        st->dataArr[st->sp++]=data;
        return STACK_DONE;
    }
    else{
        return STACK_FULL;
    }

}

void stack_delete(stack_t** st){

    free((*st)->dataArr);
    free(*st);
    *st=0;

}


/***********by using Linked List************************************/



stack_node* create_StackNode(int data){

    stack_node* newNode=malloc(sizeof(stack_node));
    if(newNode==NULLPTR){
        //stack is FULL
        return 0;
    }
    newNode->next=NULLPTR;
    newNode->prev=NULLPTR;
    newNode->data=data;

    return newNode;

}

stack_t_LL* create_Stack_LinkedList(void){

    stack_t_LL*newStack=malloc(sizeof(stack_t_LL));

    newStack->size=0;
    newStack->head=NULLPTR;
    newStack->tail=NULLPTR;

    return newStack;

}


stackStatus_t stack_push_LL(stack_t_LL* list,int Data ){
    stack_node*newNode=malloc(sizeof(stack_node));
    if(newNode==NULLPTR){
        return STACK_FULL;
    }
    newNode->data=Data;
    if(list->size==0){
        list->tail=newNode;
        list->head=newNode;

    }
    else{
        newNode->prev=list->tail;
        list->tail=newNode;
        newNode->prev->next=newNode;

    }
    list->size++;
    return STACK_DONE;


}

stackStatus_t stack_pop_LL(stack_t_LL*list,int *poped_Data){
    stack_node*tmpNode=malloc(sizeof(stack_node));

    if(list->size==0){
            //can't pop element due to stack is empty
        *poped_Data=-1;
        return STACK_EMPTY;
    }
    else{
        *poped_Data=list->tail->data;

        tmpNode=list->tail;
        list->tail=list->tail->prev;
        free(tmpNode);


    }
    return STACK_DONE;

}



