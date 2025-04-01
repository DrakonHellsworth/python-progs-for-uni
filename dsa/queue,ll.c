//DONE
//implement queue through a linked list and perform enqueue dequeue and display on it
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL;
struct node *newnode(int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->d=data;
    temp->n=NULL;
    return temp;
}
void enqueue(int data)
{
    struct node *temp=newnode(data);
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
void dequeue()
{
    if(head==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp=head;
        head=head->n;
        printf("Dequeued element is %d\n",temp->d);
        free(temp);
    }   
}
void display()
{
    if(head==NULL)
    {
        printf("Queue is empty");
    }
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->d);
        temp=temp->n;
    }
    printf("\n");
}
int main()
{
    int choice,data;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                dequeue();
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
return 0;
}