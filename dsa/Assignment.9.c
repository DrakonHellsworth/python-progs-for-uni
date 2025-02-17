//Reverse a doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *p;
    struct node *n;
};
struct node *head=NULL;
struct node *insert(int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=data;
    new->n=NULL;
    new->p=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        struct node *temp=head;
        while(temp->n!=NULL)
        {
            temp=temp->n;
        }
        temp->n=new;
        new->p=temp;
    }
    return head;
}
void display(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->d);
        temp=temp->n;
    }
    printf("\n");
}
void reverse()
{
    struct node *prev=NULL, *curr=head, *next=NULL;
    while(curr!=NULL)
    {
        next=curr->n;
        curr->n=prev;
        curr->p=next;
        prev=curr;
        curr=next;
    }
    head=prev;
}
int main()
{
    int n,i,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        insert(data);
    }
    printf("Original list: ");
    display(head);
    reverse();
    printf("Reversed list: ");
    display(head);
    return 0;
}
