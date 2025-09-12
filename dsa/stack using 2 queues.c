// create a stack using 2 queues and perform push and pop operations on it
#include<stdio.h>
int q1[100],q2[100],f1=-1,r1=-1,f2=-1,r2=-1;
void push(int x)
{
    if(r1==99)
        printf("Stack is full\n");
    else
    {
        if(f1==-1)
        {
            f1=0,r1=0;
        }
        q1[++r1]=x;
        printf("%d pushed to stack\n",x);
    }
}
void pop()
{
    if(f1==-1||f1>r1)
    {
        printf("Stack is empty\n");
        return;
    }
    if(f2==-1)
    {
        f2=0,r2=-1;
    }
    for(int i=f1;i<r1;i++)
    {
        q2[++r2]=q1[i];
    }
    printf("%d popped from stack\n",q2[r1--]);
    if(f1==r1)
    {
        f1=0,r1=-1;
    }
    for(int i=f2;i<r2;i++)
    {
        q1[i]=q2[i];
    }
    if(f2==r2)
    {
        f2=-1,r2=-1;
    }
}
void display()
{
    if(f1==-1||f1>r1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for(int i=f1;i<=r1;i++)
    {
        printf("%d",q1[i]);
    }
    printf("\n");
}
int main()
{
    int data,x=1,n;
    while(x)
    {
        printf("Enter\n1. to Push\n2.to Pop\n3.to Display\n4.to Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&n);
        if(n==1)
        {
            printf("Enter the data to push: ");
            scanf("%d",&data);
            push(data);
        }
        else if(n==2)
        {
            pop();
        }
        else if(n==3)
        {
            display();
        }
        else if(n==4)
        {
            x=0;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
return 0;
}    