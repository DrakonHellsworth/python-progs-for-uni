//Check if circular linked list
// Create a circular linked list and check if it is circular or not
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL;
void insert(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->d=data;
    temp->n=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node *temp1=head;
        while(temp1->n!=NULL)
        {
            temp1=temp1->n;
        }
        temp1->n=temp;
    }
}
void cinsert(int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=data;
    if(head==NULL)
    {
        new->n=new;
        head=new;
    }
    else
    {
        struct node *temp=head;
        while(temp->n!=head)
        {
            temp=temp->n;
        }
        temp->n=new;
        new->n=head;
    }
}
void display(struct node *head)
{
    if(head==NULL)
        return;
    int c=0;
    struct node *temp=head;
    do
    {
        printf("%d ",temp->d);
        temp=temp->n;
        c++;
    }
    while(temp!=head&&c<20);
    printf("\n");
}
void check()
{
    if(head==NULL)
    {
        printf("The linked list is empty.\n");
        return;
    }
    struct node *temp=head->n;
    while(temp!=NULL&&temp!=head)
    {
        temp=temp->n;
    }
    if(temp==head)
        printf("The linked list is circular.\n");
    else
        printf("The linked list is not circular.\n");
}
int main()
{
    int n,i,data,choice;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d",&n);
    printf("Choose 1 for circular linked list and 2 for non-circular linked list: ");
    scanf("%d",&choice);
    if(choice==1)
    {
        for(i=0;i<n;i++)
        {
            printf("Enter the data for node %d: ",i+1);
            scanf("%d",&data);
            cinsert(data);
        }
    }
    else if(choice==2)
    {
        for(i=0;i<n;i++)
        {
            printf("Enter the data for node %d: ",i+1);
            scanf("%d",&data);
            insert(data);
        }
    }
    else
    {
        printf("Invalid choice.\n");
        return 0;
    }
    printf("The linked list is: ");
    display(head);
    check();
    return 0;
}