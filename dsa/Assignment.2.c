//First create a loop in a user defined linked list a at a given position and then detect wether it is looped or not
//Detect loop in linked list
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int d;
    struct node *n;
};
struct node *head=NULL;
void insert(int data) 
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
        while(temp->n!=NULL)
            temp=temp->n;
        temp->n=new;
    }
}
void display() 
{
    struct node *temp=head;
    int c=0;
    while(temp!=NULL&&c<20) 
    {
        printf("%d ",temp->d);
        temp=temp->n;
        c++;
    }
    if(temp!=NULL)
    {
        printf("   list is cyclic\n");
    }
    else
    {
        printf("\n");
    }
}
void createLoop(int pos) 
{
    if(pos<=0)
        return;
    struct node *ls=head;
    int c=1;
    while(ls!=NULL&&c<pos) 
    {
        ls=ls->n;
        c++;
    }
    if(ls==NULL) 
    {
        printf("Invalid position\n");
        return;
    }
    struct node *temp=head;
    while(temp->n!=NULL)
        temp=temp->n;
    temp->n=ls;
    printf("Loop created: Last node now points to node at position %d.\n", pos);
}
void detectloop() 
{
    struct node *slow=head;
    struct node *fast=head;
    int le=0;
    while(fast!=NULL&&fast->n!=NULL) 
    {
        slow=slow->n;
        fast=fast->n->n;
        if(slow==fast) 
        {
            le=1;
            break;
        }
    }
    if(le!=1) 
    {
        printf("No loop detected.\n");
        return;
    }
    else 
    {
    printf("Loop detected.\n");
    }
}
int main() 
{
    int n,i,data,pos;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) 
    {
        printf("Enter data for node %d: ",i+1);
        scanf("%d",&data);
        insert(data);
    }
    printf("Linked list: ");
    display();
    printf("Enter the position to create a loop: ");
    scanf("%d",&pos);
    createLoop(pos);
    printf("The looped linked list:\n");
    display();
    detectloop();
    return 0;
}
