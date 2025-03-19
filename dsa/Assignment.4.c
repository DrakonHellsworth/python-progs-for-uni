//insertion in a user defined linked list
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
            temp1=temp1->n;
        temp1->n=temp;
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
    int n,data,pos;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        insert(data);
    }
    printf("The linked list is: \n");
    display();
    printf("\nEnter the position where you want to insert the new node: ");
    scanf("%d",&pos);
    printf("Enter the data for the new node: ");
    scanf("%d",&data);
    struct node *temp=head;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=data;
    new->n=NULL;
    if(pos<=0||pos>n+1)
    {
        printf("Invalid position\n");
        return 0;
    }
    else if(pos==1)
    {
        new->n=head;
        head=new;
    }
    else
    {
        for(int i=1;i<pos-1;i++)    
        {
            temp=temp->n;
        }
        new->n=temp->n;
        temp->n=new;
    }
    printf("The linked list after insertion is: ");
    display();
    return 0;
}
