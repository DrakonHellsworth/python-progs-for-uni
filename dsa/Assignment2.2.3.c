//Write a program to Implement Stack using Two Queues
#include<stdio.h>
int q1[100],q2[100],f1=-1,r1=-1,f2=-1,r2=-1;
void enq1(int x)
{
    if(r1==99)
        printf("Queue 1 is full\n");
    else
    {
        if(f1==-1)
        {
            f1=0;
        }
        q1[++r1]=x;
        printf("%d pushed to stack\n",x);
    }
}
void enq2(int x)
{
    if(r2==99)
    {
        printf("Queue 2 is full\n");
    }
    else
    {
        if(f2==-1) f2=0;
        q2[++r2]=x;
    }
}
int deq1()
{
    if(f1==-1||f1>r1)
    {
        return -1;
    }
    return q1[f1++];
}
int deq2()
{
    if(f2==-1||f2>r2)
    {
        return -1;
    }
    return q2[f2++];
}
void reset2()
{
    f2=r2=-1;
}
void pop()
{
    if(f1==-1||f1>r1)
    {
        printf("Stack is empty\n");
        return;
    }
    reset2();
    while(f1<r1)
    {
        enq2(deq1());
    }
    int p=deq1();
    printf("%d popped from stack\n",p);
    while(f2!=-1&&f2<=r2)
    {
        enq1(deq2());
    }
}
void peek()
{
    if(f1==-1||f1>r1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element is %d\n",q1[r1]);
    }
}
void disp()
{
    if(f1==-1||f1>r1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements:\n");
        for(int i=r1;i>=f1;i--)
            printf("%d\n",q1[i]);
    }
}
int main()
{
    int n,x;
    printf("Enter number of elements to push: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&x);
        enq1(x);
    }
    while(1)
    {
        int c;
        printf("1.Pop 2.Peek 3.Display 4.Exit\nEnter choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: 
            {
                pop(); 
                break;
            }
            case 2: 
            {
                peek(); 
                break;
            }
            case 3: 
            {
                disp(); 
                break;
            }
            case 4: 
            {
                return 0;
            }
            default: 
            {
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}
