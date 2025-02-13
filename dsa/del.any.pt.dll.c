//delete a node from a user defined doubly linked list at any given position
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node *p;
    struct node *n;
};
struct node *head=NULL;
void display(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->d);
        temp=temp->n;
    }
}
void insert(int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=data;
    new->p=NULL;
    new->n=NULL;
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
}
void del(int pos)
{
    if(head==NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct node *temp=head,*prev=NULL;
    if(pos==1)
    {
        head=head->n;
        free(temp);
        return;
    }
    for(int i=1;temp!=NULL && i<pos;i++)
    {
        prev=temp;
        temp=temp->n;
    }
    if(temp==NULL)
    {
        printf("Invalid position!\n");
        return;
    }
    prev->n=temp->n;
    free(temp);
}
int main()
{
    int n,data,pos;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        insert(data);
    }
    display(head);
    printf("\nEnter the position of the node you want to delete: ");
    scanf("%d",&pos);
    del(pos);
    display(head);
    return 0;
}