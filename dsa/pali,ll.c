//done
// to check wether a list is a plaindrome or not(with least usage of space and time complexity)
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
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->d=data;
    new->n=head;
    head=new;
}
void checkplaindrome()
{
    struct node *slow=head;
    struct node *fast=head;
    while(fast!=NULL&&fast->n!=NULL)
    {
        slow=slow->n;    
        fast=fast->n->n;  
    }
    struct node *mid=slow;
    struct node *prev=NULL;
    struct node *curr=mid;
    struct node *next=NULL;
    while(curr!=NULL)
    {
        next=curr->n;
        curr->n=prev;
        prev=curr;
        curr=next;
    }
    mid=prev;
    struct node *left=head;
    struct node *right=mid;
    while(right!=NULL)
    {
        if(left->d!=right->d)
        {
            printf("not plaindrome\n");
            return;
        }
        left=left->n;
        right=right->n;
    }
    printf("plaindrome\n");
    return;
}
int main()
{
    int n,data;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        create(data);
    }
    checkplaindrome();
    return 0;
}
