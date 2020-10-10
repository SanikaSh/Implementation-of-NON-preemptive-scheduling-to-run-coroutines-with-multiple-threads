// Implementing Queue:
#include <stdio.h>
#include <stdlib.h>
#include "TCB.h"

TCB_t * NewItem(int data)
{
    TCB_t * new_item = (TCB_t*)malloc(sizeof(TCB_t));
    new_item->next = NULL;
    new_item->prev = NULL;
    
    return new_item;
}

TCB_t * newQueue()
{
    TCB_t * head = NULL;
    return head;
}

void AddQueue(TCB_t** head, TCB_t* item)
{
    if((*head)==NULL)
    {
        //item is first elem
        *head = item;
        item->next = item->prev = item;
    }
    else
    {
       TCB_t * last_item = (*head)->prev;
       last_item->next = item;
       item->prev = last_item;
       item->next = *head;
       (*head)->prev = item;
    }
    
}

TCB_t* DelQueue(TCB_t** head)
{
    TCB_t* deletedItem = (*head);
    if((*head) == NULL)
        printf("ERROR: Queue is Empty");
    else
    {
        //head is pointing to last item:
        if((*head)->next == (*head))
        {
            (*head)->prev = (*head)->next = NULL;
            (*head) = NULL;
        }
        else
        {   
            TCB_t* last_elem = (*head)->prev;
            last_elem->next = (*head)->next;    
            (*head) = (*head)->next;       
            (*head)->prev = last_elem;
        }
        
        
    }

    //printf("%d\t", deletedItem->payload);
    return deletedItem;
    
}

