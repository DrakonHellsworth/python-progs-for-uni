
// to reverse a singly linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL;
struct node *reverse(struct node *head)
{
    struct node *prev=NULL;
    struct node *curr=head;
    struct node *next=NULL;
    while (curr!=NULL)
    {
        next=curr->n;
        curr->n=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}
void display(struct node *head)
{
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->d);
        temp=temp->n;
    }
}
int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i=0;i<n;i++)
    {
        struct node *new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d",&new->d);
        new->n=head;
        head=new;
    }
    printf("Original Linked List: ");
    display(head);
    printf("\nReversed Linked List: ");
    head=reverse(head);
    display(head);
    return 0;
}