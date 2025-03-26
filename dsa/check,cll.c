//done
// check wether a link is circular at any point or not
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
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->d=data;
    newnode->n=head;
    head=newnode;
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
int isCircular(struct node *head)
{
    struct node *temp=head;
    while(temp->n!=NULL)
    {
        temp=temp->n;
    }
    if(temp==head)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    }
int check(struct node *head)
{
    if(isCircular(head))
    {
        printf("The linked list is circular\n");
        return 0;
    }
    else
    {
        printf("The linked list is not circular\n");
        return 0;
    }
    }
int main()
{
    int n,i,data;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insert(data);
    }
    display(head);
    if(check(head))
    {
        printf("The linked list is circular.\n");
    }
    else
    {
        printf("The linked list is not circular.\n");
    }
    return 0;
}