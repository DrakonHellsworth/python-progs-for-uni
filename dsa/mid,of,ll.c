//done
//find the middle of linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void create(int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    head=temp;
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int find_middle()
{
    struct node *slow=head;
    struct node *fast=head;
    while (fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
int main()
{
    int n ,i;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int data;
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        create(data);
    }
    display();
    int x=find_middle();
    printf("\nMiddle element of the linked list is %d",x);
    return 0;
}