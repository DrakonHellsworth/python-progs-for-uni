//Linked list length even or odd
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;  
};
struct node *head=NULL;
int length(struct node *head)
{
    int cnt=0;
    while(head!=NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}
int main()
{
    int i,n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=head;
        head=newnode;
    }
    int len=length(head);
    if(len%2==0)
    {
    printf("The length of the linked list is even: %d\n",len);
    }
    else
    {
    printf("The length of the linked list is odd: %d\n",len);
    }
}