#include "q.h"

int main()
{
    Node* head = newQueue();
    AddQueue(&head, NewItem(1));
    AddQueue(&head, NewItem(2));
    AddQueue(&head, NewItem(3));
    AddQueue(&head, NewItem(4));

    //print Q:

    Node* temp = head;
    while(1)
    {
        printf("%d\t",temp->payload);
        temp = temp->next;
        if(temp==head)
            break;
    }
    printf("\nDeleting queue with head=%d\n", head->payload);
    while(1)
    {
        Node* temp = DelQueue(&head);
        printf("%d\t", temp->payload);
        if(head==NULL)
            break;
    }
        
    //while(1);
}