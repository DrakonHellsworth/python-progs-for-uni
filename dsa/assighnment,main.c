//Add Two Numbers Represented as Linked Lists
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node* n;
};
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;
struct node* addTwoNumbers(struct node *head1, struct node *head2, struct node *head3)
{
    struct node *current1 = head1;
    struct node *current2 = head2;
    struct node *current3 = head3;
    int carry = 0;
    while (current1 != NULL || current2 != NULL || carry != 0)
    {
        int sum = 0;
        if (current1 != NULL)   
        {
            sum += current1->d;
            current1 = current1->n;
        }
        if (current2 != NULL)   
        {
            sum += current2->d;
            current2 = current2->n;
        }
        sum += carry;
        carry = sum / 10;
        struct node *newNode = malloc(sizeof(struct node));
        newNode->d = sum % 10;
        if (current3 == NULL)   
        {
            head3 = newNode;
            current3 = newNode;
        }
        else   
        {
            current3->n = newNode;
            current3 = newNode;
        }
    }
    return head3;
}
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    head1 = addTwoNumbers(head1, head2, head3);
    return 0;    
}