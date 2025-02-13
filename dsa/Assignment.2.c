//Detect loop in a linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
int main()
{
    struct node *ptr1, *ptr2;
    ptr1 = (struct node *)malloc(sizeof(struct node));
    ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr1->data = 1;
    ptr1->next = ptr2;
    ptr2->data = 2;
    ptr2->next = ptr1;
    head = ptr1;
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
    while (ptr1 != ptr2)    
    {
        if (ptr1==NULL || ptr2==NULL)
        {
            printf("No loop in the linked list");
        }
        else
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (ptr1 == ptr2)
            {
                printf("Loop detected in the linked list");
            }
        }
    }
    return 0;
}