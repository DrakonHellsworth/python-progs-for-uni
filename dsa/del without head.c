//delete a node without head be taking t as the pointer towards the first node that is returned in the first function create
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL;
struct node *create(int data)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->d=data;
    new->n=NULL;
    if(head==NULL)
    {
        head=new;
        struct node *t;
        t->n=new;
        return t;
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
void del(struct node *t,int data)
{
    if(t==NULL)
    {
        printf("List is empty");
        return;
    }
    while(t->n->d!=data)
    {
        t=t->n;
    }
    printf("Deleted %d\n",t->n->d);
    struct node *temp=t->n;
    t->n=t->n->n;
    free(temp);
}
void display()
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->d);
        temp=temp->n;
    }
    printf("NULL\n");
}
int main()
{
    int n,x=1,data;
    struct node *t;
    while(x)
    {
        printf("Enter\n1.Create\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&n);
        if(n==1)
        {
            printf("Enter the data: ");
            scanf("%d",&data);
            t=create(data);
        }
        else if(n==2)
        {
            printf("Enter the data to delete: ");
            scanf("%d",&data);
            del(t,data);
        }
        else if(n==3)
        {
            display();
        }
        else if(n==4)
        {
            x=0;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
return 0;
}