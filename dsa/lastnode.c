//done
// Find the address of last node of the linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;   
    struct node *n;
};
int main()
{
    struct node *first=NULL;
    struct node *second=NULL;
    struct node *third=NULL;
    first=(struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    first->d=1;
    first->n=second;
    second->d=2;
    second->n=third;
    third->d=3;
    third->n=NULL;
    struct node *ptr=first;
    while(ptr->n!=NULL)
    {
        ptr=ptr->n;
    }
    printf("Address of last node: %p\n",ptr);
return 0;
}