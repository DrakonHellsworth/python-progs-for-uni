//implement queue using stack and perform enqueue dequeue and display on it
#include <stdio.h>
int s1[100];
int s2[100];    
int top1=-1;
int top2=-1;
void enqueue(int x)
{
    if(top1==-1)
    {
        top1=0;
        s1[top1]=x;
    }
    else
    {
        s1[++top1]=x;
    }
}
void dequeue()
{
    if(top1==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        if(top2==-1)
        {
            while(top1>=0)
            {
                s2[++top2]=s1[top1--];
            }
            printf("Dequeued element is %d\n",s2[top2--]);
            while(top2>=0)
            {
                s1[++top1]=s2[top2--];
            }
        }
    }
}
void display()
{
    if(top1==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(int i=0;i<=top1;i++)
        {
            printf("%d ",s1[i]);
        }
        printf("\n");   
    }
}
int main()
{
    int data;
    while(1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d",&data);
                enqueue(data);
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
    return 0;
}
