//done
// a program to count the size of the linked list wether it is even or odd
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL;
void create( int data )
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->d=data;
    newnode->n=head;
    head=newnode;
}
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
int main()
{
    int i,n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        create(data);
    }
    display(head);
    int cnt=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->n;
    }
    printf("\nLength of linked list is %d and it is %s\n",cnt,(cnt%2==0)?"even":"odd");
    return 0;
}