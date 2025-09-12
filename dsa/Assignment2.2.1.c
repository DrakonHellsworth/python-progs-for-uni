// Write a program to perform the following tasks:
//  a. Enqueue 5 elements into the queue.
//  b.Print the front element. 
// c. Dequeue 2 elements from the queue. 
// d. Print the front element after dequeuing. 
// e. Check if the queue is empty. 
// f. Check if the queue is full.
#include<stdio.h>
int q[100],f=-1,r=-1;
void enqueue(int x)
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
void dequeue()
{
    if(f==r)
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
    if(f==r)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element is %d\n",q[f]);
    }
}
int main()
{
    int n;
    printf("Enter the number of elements to enqueue into the queue: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        printf("Enter element %d:",i+1);
        scanf("%d", &x);
        enqueue(x);
    }
    peek();
    dequeue();
    dequeue();
    peek();
    if(f==r)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is not empty\n");
    }
    if(r==99)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Queue is not full\n");
    }
    return 0;
}
