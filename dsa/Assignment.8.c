// Print linked list elements
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
    while(temp!=NULL)
    {
        printf("%d ",temp->d);
        temp=temp->n;   
    }
}
int main()
{
    int n,data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i=0;i<n;i++)
    {
    printf("Enter data for node %d: ",i+1);
    scanf("%d",&data);
    insert(data);   
    }
    display();
    return 0;
}