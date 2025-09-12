//create a program to display binary tree in tree format
#include<stdio.h>
#include<stdlib.h>
#define SPACE 5
struct node 
{
    int d;
    struct node *l;
    struct node *r;
};
struct node* create() 
{
    int x;
    printf("Enter data (-1 for NULL):");
    scanf("%d",&x);
    if(x==-1) 
    {
        return NULL;
    }
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->d=x;
    printf("Enter left child of %d:\n",x);
    new->l=create();
    printf("Enter right child of %d:\n",x);
    new->r=create();
return new;
}
void display(struct node *root,int s) 
{
    if(root==NULL) 
    {
        return;
    }
    s+=SPACE;
    display(root->r,s);
    
    printf("\n");
    for(int i=SPACE;i<s;i++)
    {
        printf(" ");
    }
    printf("%d\n",root->d);
    display(root->l,s);
}
int main() 
{
    struct node *root=NULL;
    root=create();
    printf("\nTree structure:\n");
    display(root,0);
    return 0;
}
