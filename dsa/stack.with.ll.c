//Create a stack using linked list
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int d;
    struct node *n;
};
struct node *head=NULL;
void push(int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=data;
    new->n=head;
    head=new;
}
int pop()
{
    if (head==NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    int data=head->d;
    struct node *temp=head;
    head=head->n;
    free(temp);
    return data;
}
void display()
{
    struct node *temp=head;
    while (temp!=NULL)
    {
    printf("%d ",temp->d);
    temp=temp->n;
    }
}
int main()
{
    int choice,data;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");        
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1)
                {
                    printf("Popped data: %d\n", data);
                }
                break;
            case 3:
                display();
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}