//create a graph and perform BFS traversal on it
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *adj[100];
int vis[100];
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
void bfs(int s)
{
    int q[100],f=0,r=0;
    q[r++]=s;
    vis[s]=1;
    while(f<r)
    {
        int u=q[f++];
        printf("%d->",u);
        struct node *t=adj[u];
        while(t!=NULL)
        {
            if(!vis[t->d])
            {
                q[r++]=t->d;
                vis[t->d]=1;
            }
            t=t->n;
        }
    }
    printf("NULL\n");
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
        printf("Enter edge %d (u v): ",i+1);
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    printf("Enter starting node for BFS:");
    scanf("%d",&s);
    printf("BFS Traversal:");
    bfs(s);
    return 0;
}
