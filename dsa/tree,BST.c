//create a program to create a binary tree
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int d;
    struct node *l;
    struct node *r;
};
struct node *root=NULL;
void create(int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=data;
    new->l=NULL;
    new->r=NULL;
    if(root==NULL) 
    {
        root=new;
    } 
    else 
    {
        struct node *temp = root;
        while(1) 
        {
            if(data<temp->d) 
            {
                if(temp->l==NULL) 
                {
                    temp->l=new;
                    break;
                } 
                else 
                {
                    temp=temp->l;
                }
            } 
            else 
            {
                if(temp->r==NULL) 
                {
                    temp->r=new;
                    break;
                } 
                else 
                {
                    temp=temp->r;
                }
            }
        }
    }
}
void inorder(struct node *temp) 
{
    if(temp!=NULL) 
    {
        inorder(temp->l);
        printf("%d->", temp->d);
        inorder(temp->r);
    }
}
void preorder(struct node *temp) 
{
    if(temp!=NULL) 
    {
        printf("%d->",temp->d);
        preorder(temp->l);
        preorder(temp->r);
    }
}
void postorder(struct node *temp) 
{
    if(temp!=NULL) 
    {
        postorder(temp->l);
        postorder(temp->r);
        printf("%d->",temp->d);
    }
}
void display() 
{
    if(root==NULL) 
    {
        printf("Tree is empty\n");
    } 
    else 
    {
        printf("Inorder traversal of the binary tree:\n");
        inorder(root);
        printf("NULL");
        printf("\nPreorder traversal of the binary tree:\n");
        preorder(root);
        printf("NULL");
        printf("\nPostorder traversal of the binary tree:\n");
        postorder(root);
        printf("NULL");

    }
}
int main() 
{
    int n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        printf("Enter data for node %d: ",i+1);
        scanf("%d",&data);
        create(data);
    }
    display();
    return 0;
}
