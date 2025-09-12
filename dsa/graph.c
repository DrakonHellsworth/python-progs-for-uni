//create a program to create a graph and display it using adjacency list and check what type of graph it is, directed or undirected and perform bfs and dfs on it
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct graph
{
    int v;
    struct node *adj[MAX];
};
struct node
{
    int d;
    struct node *n;
};
int create(struct graph *g,int v)
{
    g->v=v;
    for(int i=0;i<g->v;i++)
    {
        g->adj[i]=NULL;
    }
}
void insert(struct graph *g,int s,int d,int dir)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->d=d;
    new->n=g->adj[s];
    g->adj[s]=new;

    if(dir==0)
    {
        new=(struct node*)malloc(sizeof(struct node));
        new->d=s;
        new->n=g->adj[d];
        g->adj[d]=new;
    }
}
void display(struct graph *g)
{
    for(int i=0;i<g->v;i++)
    {
        struct node *temp=g->adj[i];
        printf("%d->",i);
        while(temp!=NULL)
        {
            printf("%d->",temp->d);
            temp=temp->n;
        }
        printf("NULL\n");
    }
}    
void bfs(struct graph *g,int s)
{
    int visited[MAX]={0};
    int queue[MAX];
    int front=-1,rear=-1;
    queue[++rear]=s;
    visited[s]=1;
    printf("BFS Traversal: ");
    while(front!=rear)
    {
        front++;
        int u=queue[front];
        printf("%d->",u);
        struct node *temp=g->adj[u];
        while(temp!=NULL)
        {
            if(visited[temp->d]==0)
            {
                queue[++rear]=temp->d;
                visited[temp->d]=1;
            }
            temp=temp->n;
        }
    }
    printf("NULL\n");
    printf("BFS Traversal completed\n");
}
void dfs(struct graph *g,int s,int visited[])
{
    visited[s]=1;
    printf("%d->",s);
    struct node *temp=g->adj[s];
    while(temp!=NULL)
    {
        if(visited[temp->d]==0)
        {
            dfs(g,temp->d,visited);
        }
        temp=temp->n;
    }
}
int main()
{
    struct graph g;
    int v,e,s,d,dir;
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    create(&g,v);
    printf("Enter the number of edges: ");
    scanf("%d",&e);
    printf("Enter 0 for undirected graph and 1 for directed graph: ");
    scanf("%d",&dir);

    for(int i=0;i<e;i++)
    {
        printf("Enter the source and destination vertices: ");
        scanf("%d%d",&s,&d);
        insert(&g,s,d,dir);
    }
    display(&g);
    printf("Enter the starting vertex for bfs: ");
    scanf("%d",&s);
    bfs(&g,s);
    printf("\nEnter the starting vertex for dfs: ");
    scanf("%d",&s);
    int visited[MAX]={0};
    dfs(&g,s,visited);
    printf("NULL\n");
    return 0;
} 