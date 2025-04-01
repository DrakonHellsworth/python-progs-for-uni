//first make a loop out of the user defined linked list from the user defined point and then show it and then delete the loop
//Remove loop in linked list
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
        printf("-----list is cyclic\n");
    }
    printf("\n");
}
void createLoop(int pos) 
{
    if(pos<=0)
        return;
    struct node *h=head;
    int c=1;
    while(h!=NULL&&c<pos) 
    {
        h=h->n;
        c++;
    }
    if(h==NULL) 
    {
        printf("Invalid position\n");
        return;
    }
    struct node *temp=head;
    while(temp->n!=NULL)
        temp=temp->n;
    temp->n=h;
    printf("Loop created: Last node now points to node at position %d.\n", pos);
}
void rmloop() 
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
    slow=head;
    if(slow==fast) 
    {
        while(fast->n!=slow)
            fast=fast->n;
    }
    else 
    {
        while(slow->n!=fast->n) 
        {
            slow=slow->n;
            fast=fast->n;
        }
    }
    fast->n=NULL;
    printf("The loop has been removed.\n");
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
    rmloop();
    printf("Linked list after loop removal: ");
    display();
    return 0;
}
