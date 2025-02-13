//done
// insert a user defined node in the middle of a user defined singly linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL;
struct node *insert_node(struct node *head, int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=data;
    new->n=head;
    head=new;
    return head;
}
int find_middle(struct node *head)
{
    struct node *slow=head;
    struct node *fast=head;
    while (fast!=NULL&&fast->n!=NULL)
    {
        slow=slow->n;
        fast=fast->n->n;
    }
    return slow->d;
}
struct node *insert_middle(struct node *head, int data, int pos)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    struct node *temp=head;
    new_node->d=data;
    for(int i=0;i<pos-1;i++)
    {
        temp=temp->n;
    }
    new_node->n=temp->n;
    temp->n=new_node;
    return head;
}
int main()
{
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i=0;i<n;i++)
    {
    printf("Enter data for node %d: ",i+1);
    scanf("%d",&data);
    head=insert_node(head,data);
    }
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->d);
        temp=temp->n; 
    }
    int pos;
    pos=find_middle(head);
    printf("\n Enter the data to be inserted in the middle: ");
    scanf("%d",&data);
    head=insert_middle(head,data,pos);
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->d);
        temp=temp->n;
    }
    printf("\n");
    return 0;
}