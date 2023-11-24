
#include "list.h"




node_t *createNode(int data)
{

    node_t *newNode;
    newNode=malloc(sizeof(node_t));
    newNode->data=data;
    newNode->next=NULLPTR;
    return newNode;

}

void list_print(node_t*head)
{

    node_t* current=head;

    while(current!=NULLPTR)
    {
        printf("%d ",current->data);
        current=current->next;
    }


}

void list_print_last(node_t *head)
{

    node_t* current=head;

    if(current==NULLPTR)
    {
        return;
    }
    list_print_last(current->next);
    printf("%d ",current->data);


}


void list_addNodeToLast(node_t**phead,int data)
{

    node_t *current=*phead;
    node_t* newNode=createNode(data);

    /*to add to last if list is empty*/
    if(*phead==NULLPTR)
    {
        newNode->next=*phead;
        *phead=newNode;
        return ;
    }
    while(current->next!=NULLPTR)
    {
        current=current->next;
    }
    current->next=newNode;

}


void list_addNodeToFirst(node_t**head,int data)
{

    node_t *newNode=createNode(data);

    newNode->next=(*head);

    (*head)=newNode;

}


listStatus_t list_editNode(node_t* head,int oldData,int data)
{

    if(head==NULLPTR)
    {
        return LIST_EMPTY;
    }

    node_t *current=head;

    while(current!=NULLPTR)
    {

        if(current->data==oldData)
        {
            current->data=data;
            return LIST_DONE;
        }
        current=current->next;
    }

    return NOT_FOUND;


}

listStatus_t list_removeData(node_t **phead,int oldData)
{

    node_t *temp;
    node_t *current;
    if(*phead==NULLPTR)
    {
        return LIST_EMPTY;
    }
    else if((*phead)->data==oldData)
    {
        temp=*phead;
        *phead=temp->next;
        free(temp);
    }
    else
    {
        current=*phead;
        while(current->next!=NULLPTR)   //  1   2   3
        {
            if(current->next->data==oldData)
            {
                temp=current->next;
                current->next=temp->next;
                free(temp);
                return LIST_DONE;
            }
            current=current->next;
        }
    }
    return NOT_FOUND;


}

listStatus_t list_insertAfter(node_t *head,int prevData,int Data)
{
    node_t *newNode=createNode(Data);

    node_t *current=head;

    while(current!=NULLPTR)
    {
        if(current->data==prevData)
        {
            newNode->next=current->next;
            current->next=newNode;
            return LIST_DONE;
        }
        current=current->next;
    }

    return NOT_FOUND;


}




dlist_t* DoubleList_create(void)
{
    dlist_t *l=malloc(sizeof(dlist_t));
    l->head=NULLPTR;
    l->tail=NULLPTR;
    l->size=0;

    return l;
}


dnode_t* CreateDoubleNode(int data)
{

    dnode_t *newNode;
    newNode=malloc(sizeof(dnode_t));
    newNode->data=data;
    newNode->next=NULLPTR;
    newNode->prev=NULLPTR;
    return newNode;

}

void DoubleList_addNodeToLast(dlist_t *list,int data)
{

    dnode_t *newNode=CreateDoubleNode(data);

    newNode->prev=list->tail;
    list->tail=newNode;
    if(list->head==NULLPTR)
    {
        list->head=newNode;
    }
    else
    {
        newNode->prev->next=newNode;
    }
    list->size++;
}
