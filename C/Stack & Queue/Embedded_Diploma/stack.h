
#define STACK_SIZE  10


typedef enum{
STACK_FULL,
STACK_EMPTY,
STACK_DONE

}stackStatus_t;


stackStatus_t push(int data);

stackStatus_t pop(int *pdata);
