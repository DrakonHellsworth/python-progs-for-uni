//deletion of a node in a doubly linked list by the value in the node
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *p;
    struct node *n;
};
struct node *head=NULL;
struct node *tail=NULL;
void insert(int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=data;
    new->n=NULL;
    if(head==NULL)
    {
        head=new;
        tail=new;
        new->p=NULL;
    }
    else
    {
        tail->n=new;
        new->p=tail;
        tail=new;
    }
}
void delete(int data)
{
    struct node *temp=head;
    if(temp==NULL)
    { 
        return; 
    }
    if(temp->d==data)
    {
        head=temp->n;
        if(head!=NULL)
        { 
            head->p=NULL;
        }
        free(temp);
        return;
    }
    while(temp->n!=NULL)
    {
        if(temp->n->d==data)
        {
            struct node *del=temp->n;
            temp->n=del->n;
            if(del->n!=NULL)
            { 
                del->n->p=temp;
            }
            else
            {
                tail=temp;
            }
            free(del);
            return;
        }
        temp=temp->n;
    }
}
void display()
{
    if(head==NULL)
    {
        printf("List is empty\n"); 
    }
    else
    {
        struct node *temp=head;
        while(temp!=NULL)
        {
            printf("%d->",temp->d);
            temp=temp->n;
        }
        printf("NULL\n");
    }
}
int main()
{
    int n,v,i,data;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        insert(data);
    }
    display();
    printf("Enter the value of the node to be deleted: ");
    scanf("%d",&v);
    delete(v);
    display();
    return 0;
}
