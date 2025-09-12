//) Write a program to Print all elements of a queue in a new line
#include<stdio.h>
int q[100],f=-1,r=-1;
void enq(int x)
{
    if(r==99)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(f==-1)
        {
            f=0;
        }
        q[++r]=x;
        printf("%d enqueued to queue\n",x);
    }
}
void deq()
{
    if(f==-1||f>r)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d dequeued from queue\n",q[f++]);
    }
}
void peek()
{
    if(f==-1||f>r)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element is %d\n",q[f]);
    }
}
void disp()
{
    if(f==-1||f>r)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements:\n");
        for(int i=f;i<=r;i++)
        {
            printf("%d\n",q[i]);
        }
    }
}
int main()
{
    int n,x;
    printf("Enter the number of elements to enqueue into the queue: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&x);
        enq(x);
    }
    disp();
    return 0;
}
