// create an input restricted queue and perform enqueue dequeue and display operations
#include <stdio.h>
int q[100];
int f=-1;
int r=-1;
void enqueue(int x)
{
    if(r==99)
    {
        printf("Queue is full\n");
    }
    else
    {
        r=r+1;
        q[r]=x;
    }
}
void dequeue(int c)
{
    if(f==-1&&r==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        if(c==1)
        {
            printf("Deleted item from front of the queue is:%d\n",q[f]);
            f++;
        }
        else
        {
            printf("Deleted item from rear of the queue is:%d\n",q[r]);
            r--;
        }
    }
}
void display()
{
    int i;
    if(f==-1&&r==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(i=f;i<=r;i++)
        {
            printf("%d ",q[i]);
        }
        printf("\n");
    }
}
int main()
{
    int a,c,x;
    while(1)
    {
        printf("Enter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter 4 to exit\n");
        printf("Enter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d",&x);
                enqueue(x);
                break;    
            case 2:
                printf("Enter 1 to delete from front\nEnter 2 to delete from rear\n");
                scanf("%d",&a);
                dequeue(a);
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