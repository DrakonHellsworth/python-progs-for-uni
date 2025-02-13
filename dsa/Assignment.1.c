//Remove loop in liked list
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *head=NULL;
int main()
{
    int n,i,data;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data of node %d: ",i+1);
        scanf("%d",&data);
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->data=data;
        new->next=head;
        head=new;
    }
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==5)
        {
            temp->next=temp->next->next;
        }
        else
        {
            temp=temp->next;
        }
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);    
        temp=temp->next;
    }
    return 0;
}
