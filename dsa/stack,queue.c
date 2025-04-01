//implement stack using 2 queues and perform push pop and display on it
#include <stdio.h>
int q1[100],q2[100];
int f1=-1,r1=-1;
int f2=-1,r2=-1;
void push(int x) 
{
    if(f1==-1&&r1==-1)
    {
        f1=r1=0;
        q1[r1]=x;
    } 
    else
    {
        f2=0;
        r2=0;
        while(f1<=r1) 
        {
            q2[r2++]=q1[f1++];
        }
        f1=r1=0;
        q1[r1]=x;
        while(f2<r2) 
        {
            q1[++r1]=q2[f2++];
        }
        f2=-1;
        r2=-1;
    }
}
void pop()
{
    if(f1==-1||f1>r1) 
    {
        printf("Stack underflow\n");
    } 
    else 
    {
        printf("Popped: %d\n",q1[f1++]);
        if(f1>r1)
        { 
        f1=-1;
        r1=-1;
        } 
    }
}
void display() 
{
    if(f1==-1||f1>r1) 
    {
        printf("Stack is empty\n");
    } 
    else 
    {
        for(int i=f1;i<=r1;i++) 
        {
            printf("%d",q1[i]);
        }
        printf("\n");
    }
}
int main() 
{
    int ch,x;
    while (1) 
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch) 
        {
            case 1:
                printf("Enter element to push: ");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                pop();
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
