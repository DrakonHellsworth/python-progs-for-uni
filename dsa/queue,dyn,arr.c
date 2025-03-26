//implementation of queue through dynamic array and perform enqueue dequeue and display on it
#include <stdio.h>
#include <stdlib.h>
int *q;
int f=-1;
int r=-1;
void enq(int n)
{
    int item;
    printf("Enter the item to be inserted:");
    scanf("%d", &item);
    if(f==-1&&r==-1)
    {
        f=r=0;
        q[r]=item;
    }
    else
    {
        if(f==0&&r==n-1)
        {
            printf("Queue is full\n");
        }
        else
        {
        r++;
        q[r]=item;
        }
    }
}
void deq()
{
    if(f==-1&&r==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        if (f==r)
        {
            f=r=-1;
        }
        else
        {
            printf("Deleted item is:%d\n",q[f]);
            f++;
        }
    }
}
void display()
{
    if (f==-1&&r==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for (int i=f;i<=r;i++)
        {
            printf("%d ",q[i]);    
        }
        printf("\n");
    }
}
int main()
{
    int choice,n;
    printf("Enter the size of the queue:");
    scanf("%d",&n);
    q=(int*)malloc(n*sizeof(int));  
    f=r=-1;
    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enq(n);
            break;
        case 2:
            deq();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}