//done
//count the number of each duplicated elements in a linked list
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
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=data;
    new->n=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        struct node *temp=head;
        while(temp->n!=NULL)
        {
            temp=temp->n;
        }
        temp->n=new;
    }
}
void display(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->d);
        temp=temp->n;
    }
}
int count (struct node *head,int data)
{
    int count=0;
    struct node *temp=head;
    while(temp!=NULL)   
    {
        if(temp->d==data)
        {
            count++;
        }
        temp=temp->n;
    }
    return count;
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
        create(data);
    }
    display(head);
    int cnt,d,temp=0;
    while(head!=NULL)
    {
        d=head->d;
        if(temp!=d)
        {
            cnt=count(head,d);
            if(cnt>1)
            {
                printf("\n%d is repeated %d times\n",d,cnt);
            }
        temp=d;
        }
        head=head->n;
    }
    printf("\n");
    return 0;
}
    
