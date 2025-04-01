//Given a singly linked list. The task is to remove duplicates (nodes with duplicate values) from the given list (if it exists). Note: Try not to use extra space. The nodes are arranged in a sorted way.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL;
void insert(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->d=data;
    temp->n=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    {
        struct node *temp1=head;
        while(temp1->n!=NULL)
        {
            temp1=temp1->n;
        }
        temp1->n=temp;
    }
}
struct Node* removeDuplicates(struct Node* head) 
{
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    while (current != NULL) 
    {
        next = current->n;
        while (next != NULL && next->d == current->d) 
        {
            next = next->n;
        }
        if (next == current->n) 
        {
            prev = current;
            current = next;
        } 
        else 
        {
            prev->n = next;
            current = next;
            if(prev!=NULL)  
            {
            next = prev->n;
            }
            else
        }
        }
        }
    }
}
