//Given the root of a binary tree. WAP in to Check whether it is a BST or not.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *l,*r;
};
struct node *root=NULL;
struct node *create()
{
    int x;
    printf("Enter data (-1 for NULL):");
    scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=x;
    printf("Enter left child of %d:\n",x);
    new->l=create();
    printf("Enter right child of %d:\n",x);
    new->r=create();
    return new;
}
struct node *prev=NULL;
int bst(struct node *temp)
{
    if(temp!=NULL)
    {
        if(bst(temp->l)==0)
        {
            return 0;
        }
        if(prev!=NULL && temp->d<=prev->d)
        {
            return 0;
        }
        prev=temp;
        return bst(temp->r);
    }
    return 1;
}
int main()
{
    printf("Enter the BT:\n");
    root=create();
    prev=NULL; 
    if(bst(root))
    {
        printf("Tree is a BST\n");
    }
    else
    {
        printf("Tree is NOT a BST\n");
    }
    
    return 0;
}
