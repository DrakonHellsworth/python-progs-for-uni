//count nodes of a singly linked list
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
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->d=data;
    temp->n=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else 
    {
        struct node *temp1=head;
        while(temp1->n!=NULL)
        {
            temp1=temp1->n;
        }
        temp1->n=temp;
    }
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->d);
        temp=temp->n;
    }
    printf("\n");
}
int count()
{
    int c=0;
    struct node *temp=head;
    while(temp!=NULL)   
    {
        c++;
        temp=temp->n;
    }
    return c;
}
int main()
{
    int n,i,c;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        int data;
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        insert(data);
    }
    display();
    c=count();
    printf("The number of nodes in the linked list is %d",c);
    return 0;
}