// you are given a node of a singly linked list where you have to delete a value of the given node from the linked list but you are not given the head of the list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL;
void display(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->d);
        temp=temp->n;   
    }
}
int main()
{
    struct node *new,*temp,*prev;
    int i,n,data;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        new=(struct node*)malloc(sizeof(struct node));
        new->d=data;
        new->n=NULL;
        if(head==NULL)
        {
            head=new;
            prev=new;
        }
        else
        {
            prev->n=new;
            prev=new;
        }
    }
    display(head);
    printf("\nEnter the position of the node you want to delete: ");
    scanf("%d",&i); 
    temp=head;
    if(i==1)
    {
        head=temp->n;
        free(temp);
    }
    else
    {
        int count=1;
        while(count<i-1)
        {
            temp=temp->n;
            count++;
        }   
        prev=temp;
        temp=temp->n;
        prev->n=temp->n;
        free(temp);
    }
    display(head);
    printf("\nEnter the data of the node you want to delete: ");
    scanf("%d",&data);
    temp=head;
    if(temp->d==data)
    {
        head=temp->n;
        free(temp);
    }
    else
    {
        while(temp->n!=NULL)
        {
            if(temp->n->d==data)
            {
                prev=temp;
                temp=temp->n;
                prev->n=temp->n;
                free(temp);
            }
        }
    }
}