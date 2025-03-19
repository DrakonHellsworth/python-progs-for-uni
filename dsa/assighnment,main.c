//Add Two Numbers Represented as Linked Lists
//do it like a full adder
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *insert(struct node **head,int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=data;
    new->n=NULL;
    if(*head==NULL)
    {
        *head=new;
    }
    else
    {
        struct node *temp=*head;
        while(temp->n!=NULL)
        {
            temp=temp->n;
        }
        temp->n=new;
    }
    return *head;
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
struct node *rev(struct node *head)
{
    struct node *prev=NULL;
    struct node *curr=head;
    struct node *next=NULL;
    while(curr!=NULL)
    {
        next=curr->n;
        curr->n=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
struct node *adder(struct node *head1,struct node *head2)
{
    struct node *curr1=head1;
    struct node *curr2=head2;
    struct node *head3=NULL;
    struct node *curr3=NULL;
    int carry=0;
    while(curr1!=NULL||curr2!=NULL||carry!=0)
    {
        int sum=0;
        if(curr1!=NULL)
        {
            sum+=curr1->d;
            curr1=curr1->n;
        }
        if(curr2!=NULL)
        {
            sum+=curr2->d;
            curr2=curr2->n;
        }
        sum+=carry;
        carry=sum/10;
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->d=sum%10;
        new->n=NULL;
        if(head3==NULL)
        {
            head3=new;
            curr3=new;
        }
        else
        {
            curr3->n=new;
            curr3=new;
        }
    }
    return head3;
}
int main()
{
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *head3=NULL;
    int n1,n2,i,data;
    printf("Enter the number of nodes in the first linked list: ");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        insert(&head1,data);
    }
    printf("Enter the number of nodes in the second linked list: ");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        insert(&head2,data);
    }
    head1=rev(head1);
    head2=rev(head2);
    head3=adder(head1,head2);
    head3=rev(head3);
    printf("First Number is: ");
    display(rev(head1));
    printf("Second Number is: ");
    display(rev(head2));
    printf("Sum Linked List: ");
    display(head3);
    return 0;
}
