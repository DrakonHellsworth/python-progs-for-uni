//done
//insert a node at any point  given by the user in the linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *n;
};
int main()
{
    struct node *head=NULL;
    struct node *second=NULL;
    struct node *third=NULL;
    struct node *fourth=NULL;
    struct node *fifth=NULL;
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    fifth=(struct node *)malloc(sizeof(struct node));
    head->d=1;
    head->n=second;
    second->d=2;
    second->n=third;
    third->d=3;   
    third->n=fourth;
    fourth->d=4;
    fourth->n=fifth;
    fifth->d=5;
    fifth->n=NULL;
    struct node *ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->d);
        ptr=ptr->n;
    }
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    int pos;
    printf("\nEnter the position at which you want to insert the node: ");
    scanf("%d",&pos);
    int n1;
    printf("\nEnter the value of the node: ");
    scanf("%d",&n1);
    if (pos==1)
    {
        newnode->d=6;
        newnode->n=head;
        head=newnode;
    }
    else
    {
        ptr=head;
        for(int i=1;i<pos-1;i++)
        {
            if (ptr->n==NULL)
            {
                printf("Invalid position\n");
                return 0;
            }
            ptr=ptr->n;
        }
        newnode->d=n1;
        newnode->n=ptr->n;
        ptr->n=newnode;
    }
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->d);
        ptr=ptr->n;
    }
return 0;
}
