// create a linked list with user defined number of nodes
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL;
int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&new->d);
        new->n=head;
        head=new;
    }
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->d);
        temp = temp->n;
    }
    return 0;
}