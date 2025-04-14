//create a program to create a binary tree using linked list
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int d;
    struct node *l;
    struct node *r;
};
struct node* create(int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=data;
    new->l=NULL;
    new->r=NULL;
    return new;
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
void display(struct node *root) 
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
    struct node *root=NULL;
    root=create(1);
    root->l=create(2);
    root->r=create(3);
    root->l->l=create(4);
    root->l->r=create(5);
    root->r->l=create(6);
    root->r->r=create(7);
    display(root);
    return 0;
}
