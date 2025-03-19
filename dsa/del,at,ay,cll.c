//delete a node from a circular linked list at any given position
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL;
struct node *insert(int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=data;    
    new->n=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        struct node *temp=head; 
        while(temp->n!=head)
        {
            temp=temp->n;
        }
        temp->n=new;
        new->n=head;
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
}
struct node *delete(struct node *head,int pos)  
{
    struct node *temp=head;
    struct node *prev=NULL;
    if(pos==1)
    {

        
        return head;
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            prev=temp;
            temp=temp->n;
        }
        prev->n=temp->n;
        free(temp);
        return head;
    }
}
int main()
{
    int data,pos,i,n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data: ");
        scanf("%d",&data);
        insert(data);
    }
    display(head);
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    head=delete(head,pos);
