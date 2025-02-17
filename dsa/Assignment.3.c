//Delete a node in single linked list
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
void delete(int data)
{
    struct node *temp=head;
    if(temp->d==data)
    {
        head=temp->n;
        free(temp);
    }
    else 
    {
        struct node *temp1=head;
        while(temp1->n->d!=data)
            temp1=temp1->n;
        temp1->n=temp1->n->n;
        free(temp1->n);
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
int main()
{
    int n,data;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        insert(data);
    }
    display();
    printf("Enter the data of the node to be deleted: ");
    scanf("%d",&data);
    delete(data);
    display();
    return 0;
}