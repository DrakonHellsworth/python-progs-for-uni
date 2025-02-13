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
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->next=head;
    head=new;
}
void display() 
{
    struct node *ptr=head;
    while(ptr!=NULL) 
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void remove_duplicates() 
{
    struct node *curr=head;
    struct node *run,*temp;
    while(curr!=NULL) 
    {
        run=curr;
        while(run->next!=NULL) 
        {
            if(run->next->data==curr->data) 
            {
                temp=run->next;
                run->next=run->next->next;
                free(temp);
            } 
            else 
            {
                run=run->next;
            }
        }
        curr=curr->next;
    }
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
    printf("Original linked list: ");
    display();
    remove_duplicates();
    printf("\nLinked list after removing duplicates: ");
    display();
    return 0;
}