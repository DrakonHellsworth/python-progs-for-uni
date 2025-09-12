//write a program to reverse first k elements of queue
//write a program to reverse first k elements of queue
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
    if(f==-1||f>r)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d dequeued from queue\n",q[f++]);
    }
}
void reverse(int k)
{
    if(k<=0 || k>r-f+1)
    {
        printf("Invalid value of k\n");
        return;
    }
    int i=f,j=f+k-1;
    while(i<j)
    {
        int temp=q[i];
        q[i]=q[j];
        q[j]=temp;
        i++;
        j--;
    }
}
void display()
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
            printf("%d ",q[i]);
        }
        printf("\n");
    }
}
int main()
{
    int n,k;
    printf("Enter the number of elements to enqueue into the queue: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        printf("Enter element %d: ",i+1);
        scanf("%d",&x);
        enqueue(x);
    }
    printf("Enter the number of elements to reverse: ");
    scanf("%d",&k);
    reverse(k);
    display();
    return 0;
}
