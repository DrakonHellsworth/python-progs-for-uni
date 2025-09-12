//DONE
// delete a node from a linked list before a node pointer x
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL;
void create(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->d=data;
    newnode->n=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *temp=head;
        while(temp->n!=NULL)
        {
            temp=temp->n;
        }
        temp->n=newnode;
    }
}
void delete(struct node *head,int data)
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    if(head->d==data)
    {
        struct node *temp=head;
        head=head->n;
        free(temp);
        return;
    }
    struct node *temp=head,*prev=NULL;
    while(temp!=NULL && temp->d!=data)
    {
        prev=temp;
        temp=temp->n;
    }
    if(temp==NULL)
    {
        printf("Data not found");
        return;
    }
    prev->n=temp->n;
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
    int ch,data;
    while(1)
    {
        printf("1.Create\n2.Delete\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the data: ");
                scanf("%d",&data);
                create(data);
                break;
            case 2:
                printf("Enter the data to be deleted: ");    
                scanf("%d",&data);
                delete(head,data);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}