// delete a node from a linked list after a node pointer x
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
void display()
{
    struct node *temp=head;
    printf("Linked List: ");
    while (temp!=NULL)
    {
        printf("%d ",temp->d);
        temp=temp->n;
    }
    printf("\n");
}
int main()
{
    int n,i,pos,d;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&d);
        struct node *new=create(d);
        if (head==NULL)
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
    display();
    printf("Enter the position of x: ");
    scanf("%d",&pos);
    if (pos==0)
    {
        if(head==NULL)
        {
            printf("Linked List is empty\n");
            return 0;
        }
        struct node *t=head;
        t->n=t->n->n; 
        free(t);
    }
    else
    {
        if (head==NULL)
        {
            printf("Linked List is empty\n");
            return 1;
        }
        struct node *temp=head;
        for(i=0;i<pos-1 && temp->n!=NULL;i++)
        {
            temp=temp->n;
        }
        struct node *t=temp->n;
        temp->n=temp->n->n;
        free(t);
    }
    display();
    return 0;
}
