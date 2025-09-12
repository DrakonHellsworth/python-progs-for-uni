//Given a binary tree ,WAP in C to find its height
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *l,*r;
};
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
int height(struct node *t)
{
    if(t==NULL)
    {
        return 0;
    }
    int lh=height(t->l);
    int rh=height(t->r);
    if(lh>rh)
        return lh+1;
    else
        return rh+1;
}
int main()
{
    struct node *root = NULL;
    printf("Create the binary tree:\n");
    root=create();
    printf("Height of the tree: %d\n", height(root)-1);
    return 0;
}
