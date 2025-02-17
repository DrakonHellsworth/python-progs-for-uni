// Represent a Polynomial using Linked List and display the Polynomial.(Note take the polynomial as a whole and at once example 3x^2 + 2x + 1)
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int coef;
    int exp;
    struct node *next;
};
struct node *head=NULL;
void insert(int coef,int exp)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->coef=coef;
    newnode->exp=exp;
    newnode->next=head;
    head=newnode;
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(temp->next!=NULL)
        {
    if(temp->exp==0)
    {
        printf("%d ",temp->coef);
    }
    else    
    {
        printf("%dx^%d + ",temp->coef,temp->exp);
    }
    temp=temp->next;
        }
        else
        {
            if(temp->exp==0)
            {
                printf("%d ",temp->coef);
            }
            else
            {
                printf("%dx^%d",temp->coef,temp->exp);
            }
            temp=temp->next;
        }
        }
        }
int main()
{
    int n,i;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int coef,exp;
        printf("Enter the coefficient %d: ",i+1);
        scanf("%d",&coef);
        printf("Enter the exponent %d: ",i+1);
        scanf("%d",&exp);    
        insert(coef,exp);
    }
    printf("The polynomial is: ");
    display();
    return 0;
    }
