// Implementing Queue:
#include <stdio.h>
#include <stdlib.h>
#include "TCB.h"

typedef struct Node
{
    struct Node * prev;
    struct Node * next;
    int payload;
}Node;


Node * NewItem(int data)
{
    Node * new_item = (Node*)malloc(sizeof(Node));
    new_item->next = NULL;
    new_item->prev = NULL;
    new_item->payload = data;

    return new_item;
}

Node * newQueue()
{
    Node * head = NULL;
    return head;
}

void AddQueue(Node** head, Node* item)
{
    if((*head)==NULL)
    {
        //item is first elem
        *head = item;
        item->next = item->prev = item;
    }
    else
    {
       Node * last_item = (*head)->prev;
       last_item->next = item;
       item->prev = last_item;
       item->next = *head;
       (*head)->prev = item;
    }
    
}

Node* DelQueue(Node** head)
{
    Node* deletedItem = (*head);
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
            Node* last_elem = (*head)->prev;
            last_elem->next = (*head)->next;    
            (*head) = (*head)->next;       
            (*head)->prev = last_elem;
        }
        
        
    }

    //printf("%d\t", deletedItem->payload);
    return deletedItem;
    
}

