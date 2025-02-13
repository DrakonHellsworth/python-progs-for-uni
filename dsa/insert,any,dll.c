//done
// insert a node at any given position for a user defined doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{   
    int d;
    struct node *p;
    struct node *n;
};
struct node *head=NULL;
struct node *create(int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->d=data;
    temp->p=NULL;
    temp->n=NULL;
    return temp;
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
    printf("\n");
}
void insert(struct node *head,int pos,int d)
{
    struct node *new=create(d);
    struct node *temp=head;
    if(pos==1)
    {
        new->n=head;
        head->p=new;
        head=new;
    }
    else
    {
        int i=1;
        while(i<pos-1)
        {
            temp=temp->n;
            i++;
        }
        if(temp->n==NULL)
        {
            temp->n=new;
            new->p=temp;
        }
        else
        {
            new->n=temp->n;
            new->p=temp;
            temp->n=new;
            new->n->p=new;
        }
    }
}
int main()
{
    int i,n,pos,d;
    printf("Enter the number of nodes in the linked list: "); 
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&d);
        struct node *new=create(d);
        if(head==NULL)
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
            new->p=temp;
        }
    }
    display(head);
    printf("Enter the position to be inserted: "); 
    scanf("%d",&pos);
    printf("Enter the data to be inserted: "); 
    scanf("%d",&d);
    insert(head,pos,d);
    display(head);
    return 0;
}
