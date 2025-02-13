//deletion of the middle element of a user defined linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void deleteMiddle(struct node *head)
{
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;
    struct node *prev = NULL;
    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
    }
    prev->next = slow_ptr->next;
    free(slow_ptr);
}
int main()
{
    struct node *newnode;
    struct node *temp;
    int i,n,data;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data of node %d: ",i+1);
        scanf("%d",&data);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=head;
        head=newnode;
    }
    temp=head;
    printf("\nLinked list before deletion: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    deleteMiddle(head);
    temp=head;
    printf("\nLinked list after deletion: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;    
}
