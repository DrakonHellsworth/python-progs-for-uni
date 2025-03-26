//done
// create case for insertion at beginning and at last of a circular linked list
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
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->d=data;
    newnode->n=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->n=newnode;
    }
    else
    {
        struct node *temp=head;
        while(temp->n!=head)
        {
            temp=temp->n;
        }
        temp->n=newnode;
        newnode->n=head;
    }
}
void insert_at_beginning(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->d=data;
    newnode->n=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->n=newnode;
    }
    else
    {
        struct node *temp=head;
        while(temp->n!=head)
        {
            temp=temp->n;
        }
        newnode->n=head;
        temp->n=newnode;
        head=newnode;
    }
}
void insert_at_last(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->d=data;
    newnode->n=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->n=newnode;
    }
    else
    {
        struct node *temp=head;
        while(temp->n!=head)
        {
            temp=temp->n;
        }
        temp->n=newnode;
        newnode->n=head;
    }
}
void display()
{
    if(head==NULL)
    {
        return;
    }
    struct node *temp=head;
    int count=0;
    do
    {
        printf("%d ",temp->d);
        temp=temp->n;
        count++;
    }
    while(temp!=head && count<20);
    printf("\n");
}
int main()
{
    int n,i,data,choice;
    printf("Enter the number of nodes to create: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        insert(data);
    }
    printf("The circular linked list is: ");
    display();
    printf("Enter 1 to insert at beginning, 2 to insert at last: ");
    scanf("%d",&choice);
    printf("Enter the data for the new node: ");
    scanf("%d",&data);
    if(choice==1)
    {
        insert_at_beginning(data);
    }
    else if(choice==2)
    {
        insert_at_last(data);
    }
    else
    {
        printf("Invalid choice.\n");
        return 0;
    }
    printf("The updated circular linked list is: ");
    display();
    return 0;
}
