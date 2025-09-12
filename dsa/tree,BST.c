//create a program to create a binary search tree
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
int count(struct node *t)
{
    if(t==NULL) 
    {
        return 0;
    }
    else
    {
        return 1+count(t->l)+count(t->r);
    }
}
int depth(struct node *t)
{
    if(t==NULL) 
    {
        return 0;
    }
    else
    {
        int l=depth(t->l);
        int r=depth(t->r);
        return (l>r?l:r)+1;
    }
}
int full(struct node *t)
{
    if(t==NULL) 
    {
        return 1;
    }
    if((t->l==NULL && t->r==NULL)||(t->l!=NULL && t->r!=NULL))
    {
        return full(t->l)&&full(t->r);
    }
    return 0;
}
int per(struct node *t,int d,int lv)
{
    if(t==NULL) 
    {
        return 1;
    }
    if(t->l==NULL && t->r==NULL) 
    {
        return d==lv+1;
    }
    if(t->l==NULL || t->r==NULL)
    {
        return 0;
    }
    return per(t->l,d,lv+1)&&per(t->r,d,lv+1);
}
int comp(struct node *t,int i,int n)
{
    if(t==NULL)
    {
        return 1;
    }
    if(i>=n)
    {
        return 0;
    }
    return comp(t->l,2*i+1,n)&&comp(t->r,2*i+2,n);
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
        printf("\nNumber of nodes in the binary tree: %d\n", count(root));
        printf("Depth of the binary tree: %d\n", depth(root));
        if(full(root)) 
            printf("The binary tree is full\n");
        else 
            printf("The binary tree is not full\n");
        if(per(root, depth(root), 0)) 
            printf("The binary tree is perfect\n");
        else 
            printf("The binary tree is not perfect\n");
        if(comp(root, 0, count(root))) 
            printf("The binary tree is complete\n");
        else 
            printf("The binary tree is not complete\n");
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