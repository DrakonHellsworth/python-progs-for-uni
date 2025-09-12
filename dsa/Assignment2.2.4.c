//Write a program to Implement Queue using Two Stacks
//Write a program to Implement Queue using Two Stacks
#include<stdio.h>
int s1[100],s2[100],top1=-1,top2=-1;
void enqueue(int x) 
{
    if(top1==99) 
    {
        printf("Stack 1 is full\n");
    } 
    else 
    {
        s1[++top1]=x;
        printf("%d enqueued to queue\n",x);
    }
}
void dequeue() 
{
    if(top1==-1) 
    {
        printf("Queue is empty\n");
    } 
    else 
    {
        while(top1!=-1) 
        {
            s2[++top2]=s1[top1--];
        }
        printf("%d dequeued from queue\n",s2[top2--]);
        while(top2!=-1) 
        {
            s1[++top1]=s2[top2--];
        }
    }
}
void peek() 
{
    if(top1==-1) 
    {
        printf("Queue is empty\n");
    } 
    else 
    {
        int temp1=top1,temp2=top2;
        while(temp1!=-1) 
        {
            s2[++temp2]=s1[temp1--];
        }
        printf("Front element is %d\n",s2[temp2]);
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
        printf("Queue elements:\n");
        for(int i=0;i<=top1;i++) 
        {
            printf("%d\n",s1[i]);
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
        enqueue(x);
    }
    while(1) 
    {
        int choice;
        printf("0. Enqueue\n1. Dequeue\n2. Peek\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice) 
        {
            case 0:
                printf("Enter element to enqueue: ");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 1:
                dequeue();
                break;
            case 2:
                peek();
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
