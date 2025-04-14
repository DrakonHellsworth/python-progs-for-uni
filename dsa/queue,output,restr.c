// create an output restricted queue and perform enqueue dequeue and display operations
#include<stdio.h>
int q[100];
int f=-1,r=-1;
void enqueue(int x,int c)
{
    if(c==2)
    {
        if(f==-1)
        {
            f=r=0;
            q[r]=x;
        }
        else
        {
            if(r==99)
            {
                printf("Queue is full\n");
                return;
            }
        q[++r]=x;
        }
    }
    else
    {
        if(f==-1)
        {
            f=r=0;
            q[r]=x;
        }
        else
        {
            if(f==0)
            {
                printf("The front is already at begining cannot input from front");
            }
            else 
            {
            q[--f]=x;
            }
        }
    }
}
void dequeue()
{
    if(f==-1)
    {
        printf("Queue is empty\n");
    }
    else 
    {
        if(r==f)
        {
            printf("The dequeued element is %d",q[r--]);
            f=r=-1;
        }
        else 
        {
        printf("The dequeued element is %d",q[r--]);
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
                printf("Enter 1 to enter from front\nEnter 2 to enter from rear\n");
                scanf("%d",&a);
                enqueue(x,a);
                break;    
            case 2:
                dequeue();
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