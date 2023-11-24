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
