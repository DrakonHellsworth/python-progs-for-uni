// sort and merge two linked lists
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;    
void push(struct node **head, int new_data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->d = new_data;
    new_node->n = (*head);
    (*head) = new_node; 
}
void display(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->d);
        head=head->n;
    }
}
struct node *merge(struct node *head1, struct node *head2)
{
    struct node *p1=head1;
    struct node *p2=head2;
    struct node *p3=head3;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->d<p2->d)
        {
            p3->d=p1->d;
            p3->n=NULL;
            p1=p1->n;
            p3=p3->n;
        }
        else
        {
            p3->d=p2->d;
            p3->n=NULL;
            p2=p2->n;
            p3=p3->n;
        }
    }
    while(p1!=NULL)
    {
        p3->d=p1->d;
        p3->n=NULL;
        p1=p1->n;
        p3=p3->n;
    }
    while(p2!=NULL)
    {
        p3->d=p2->d;
        p3->n=NULL;
        p2=p2->n;
        p3=p3->n;
    }
    return head3;
}
int main()
{
    int i,n;
    printf("Enter the number of nodes in the first linked list: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int data;
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        push(&head1,data);
    }
    printf("Enter the number of nodes in the second linked list: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int data;
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        push(&head2,data);
    }
    printf("First Linked List: ");
    display(head1);
    printf("\nSecond Linked List: ");
    display(head2);
    printf("\nMerged Linked List: ");
    display(merge(head1,head2));
    return 0;
}