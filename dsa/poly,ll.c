//Polynomial Representation using Linked List
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
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->coef=coef;
    new->exp=exp;
    new->next=NULL;
    if(head==NULL)
    head=new;
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(temp->next!=NULL)
        {printf("%dx^%d+",temp->coef,temp->exp);}
        else
        {printf("%dx^%d",temp->coef,temp->exp);}
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int n,i,coef,exp;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
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