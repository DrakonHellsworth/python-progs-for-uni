//Create a graph and perform DFS traversal on it
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *adj[100];
int vis[100];
void dfs(int s)
{
    vis[s]=1;
    printf("%d->",s);
    struct node *t=adj[s];
    while(t!=NULL)
    {
        if(!vis[t->d])
        {
            dfs(t->d);
        }
        t=t->n;
    }
}
void add(int u,int v)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=v;
    new->n=NULL;
    if(adj[u]==NULL)
    {
        adj[u]=new;
    }
    else
    {
        struct node *t=adj[u];
        while(t->n!=NULL)
        {
            t=t->n;
        }
        t->n=new;
    }
}
int main()
{
    int n,e,u,v,s;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter number of edges:");
    scanf("%d",&e);
    for(int i=0;i<e;i++)
    {
        printf("Enter edge %d:",i+1);
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    printf("Enter starting vertex:");
    scanf("%d",&s);
    dfs(s);
    printf("NULL\n");
    return 0;
}