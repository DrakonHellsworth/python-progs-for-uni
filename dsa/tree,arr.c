// create a user defined tree using an array without the use of structure
#include<stdio.h>
#define MAX 100
int tree[MAX];
void insert(int val,int x) 
{
    if(tree[x]!=-1) 
    {
        printf("Node already exists at index %d\n",x);
        return;
    }
    tree[x]=val;
}
void inorder(int x) 
{
    if(x>=MAX || tree[x]==-1)
        return;
    inorder(2*x+1);
    printf("%d",tree[x]);
    inorder(2*x+2);
}
int main() 
{
    for(int i=0;i<MAX;i++) 
        tree[i]=-1;
    int n,v;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        int x;
        printf("Enter value and index (starting at 0) for node %d:",i+1);
        scanf("%d%d",&v,&x);
        insert(v,x);
    }
    printf("Inorder traversal:");
    inorder(0);
    printf("\n");
    return 0;
}
