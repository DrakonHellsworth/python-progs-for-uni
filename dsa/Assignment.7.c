//Find length of loop in linked list
//create a loop in a linked list at a given position and then find the length of the loop
#include<stdio.h>
#include<stdlib.h>
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
        {
            temp=temp->n;
        }
        temp->n=new;
    }
}
void display()
{
    struct node *temp=head;
    int c=0;
    while(temp!=NULL && c<20)
    {
        printf("%d ",temp->d);
        temp=temp->n;
        c++;
    }
    if(temp!=NULL)
    {
        printf("---list is cyclic");
    }
    printf("\n");
}
void createLoop(int pos)
{
    if(pos<=0)
    {
        return;
    }
    struct node *ls=head;
    int c=1;
    while(ls!=NULL && c<pos)
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
    {
        temp=temp->n;
    }
    temp->n=ls;
    printf("Loop created: Last node now points to node at position %d.\n",pos);
}
int lengthOfloop()
{
    struct node *slow=head;
    struct node *fast=head;
    int len=0;
    while(fast!=NULL && fast->n!=NULL)
    {
        slow=slow->n;
        fast=fast->n->n;
        if(slow==fast)
        {
            struct node *ptr=slow;
            do
            {
                len++;
                ptr=ptr->n;
            }
            while(ptr!=slow);
            return len;
        }
    }
    return 0;
}
int main()
{
    int n,i,data,pos,c;
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
    c=lengthOfloop();
    printf("Length of the loop: %d\n",c);
    return 0;
}
