//done
// to insert a node in a linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL;
struct node *insert(struct node *head,int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->d=data;
    newnode->n=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *temp=head;
        while(temp->n!=NULL)
        {
            temp=temp->n;
        }
        temp->n=newnode;
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
int main()
{
    int i,n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        head=insert(head,data);
    }
    struct node *temp=head;
    printf("The linked list is: ");
    display(temp);
    printf("Enter the data to be inserted: ");
    scanf("%d",&data);
    head=insert(head,data);
    temp=head;
    printf("The linked list after insertion is: ");
    display(temp);
    return 0;
}