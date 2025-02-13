// create a program to delete a node from a singly linked list after a node pointer x
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL;
struct node *create(int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->d=data;
    temp->n=NULL;
    return temp;
}
int main()
{
    int n,i,pos;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&pos);
        struct node *new=create(pos);
        if(head==NULL)
        {
            head=new;
        }
        else
        {
            struct node *temp;
            temp=head;
            while(temp->n!=NULL)
            {
                temp=temp->n;
            }
            temp->n=new;
        }
    }
    printf("Original Linked List: ");
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->d);
        temp=temp->n;
    }
    printf("\n");
    int pos1;
    printf("Enter the position of the node to be deleted: ");
    scanf("%d",&pos1);
    if(pos1==1)
    {
        head=head->n;
        free(head);
    }
    else
    {
        struct node *temp;
        temp=head;
        for(i=1;i<pos1-1;i++)
        {
            temp=temp->n;
        }
        temp->n=temp->n->n;
        free(temp->n);
    }
    printf("Updated Linked List: ");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->d);
        temp=temp->n;
    }
    printf("\n");
    return 0;
}