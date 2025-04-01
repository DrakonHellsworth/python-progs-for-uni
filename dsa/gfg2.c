//Given the head of a linked list and the number k, Your task is to find the kth node from the end. If k is more than the number of nodes, then the output should be -1.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL;
void insert(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->d=x;
    temp->n=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node *p=head;
        while(p->n!=NULL)
        {
            p=p->n;
        }
        p->n=temp;
    }
}
void display()
{
    struct node *p=head;
    while(p!=NULL)
    {
        printf("%d->",p->d);
        p=p->n;
    }
    printf("NULL \n");
}
int kne(int k)
{
    struct node *p=head,*q=head;
    int count=0;
    while(p!=NULL)
    {
        p=p->n;
        count++;
    }
    if(count<k)
    {
        return -1;
    }
    else
    {
        for(int i=0;i<count-k;i++)
        {
            q=q->n;
        }
        return q->d;
    }
}
int main()
{
    int n,i;
    printf("Enter the number of nodes: ");
    scanf("%d",&n); 
    for(i=0;i<n;i++)
    {
        int data;
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        insert(data);
    }
    display();
    int k;
    printf("Enter the value of k: ");
    scanf("%d",&k);
    int result=kne(k);
    if(result==-1)
    {
        printf("Node does not exist \n");
    }
    else
    {
        printf("The %dth node from the end is %d \n",k,result);
    }
    return 0;
}
