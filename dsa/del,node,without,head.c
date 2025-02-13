#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int d;
    struct node *n;
};
struct node *head=NULL;
void insert(int data) 
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=data;
    new->n=head;
    head=new;
}
void display(struct node *head) 
{
    struct node *temp=head;
    while(temp!=NULL) 
    {
        printf("%d ",temp->d);
        temp=temp->n;
    }
    printf("\n");
}
void deleteNode(struct node *del) 
{
    if(del==NULL || del->n==NULL) 
    {
        printf("Cannot delete the given node (it may be the last node or NULL).\n");
        return;
    }
    struct node *temp=del->n;
    del->d=temp->d;
    del->n=temp->n;
    free(temp);
}
int main() 
{
    int n,i,data;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) 
    {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insert(data);
    }
    printf("Initial list: ");
    display(head);
    if(head!=NULL && head->n!=NULL) 
    {
        deleteNode(head);
    }
    printf("List after deletion: ");
    display(head);
    return 0;
}
