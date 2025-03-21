//implement queue through an array and perform enqueue dequeue and display on it
#include <stdio.h>
int q[100];
int f=-1;
int r=-1;
void enq()
{
    int item;
    printf("Enter the item to be inserted:");
    scanf("%d",&item);
    if(f==-1&&r==-1)
    {
        f=r=0;
        q[r]=item;
    }
    else
    {
        if(f==0&&r==99)
        {
            printf("Queue is full");
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
        printf("Deleted item is:%d\n",q[f]);
        f++;
        if(f>r)
        {
            f=r=-1;        
        }
    }
}
void display()
{
    if(f==-1&&r==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(int i=f;i<=r;i++)
        {
            printf("%d ",q[i]);
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enq();
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