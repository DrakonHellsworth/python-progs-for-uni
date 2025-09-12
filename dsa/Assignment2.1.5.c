//Wap to delete middle element from stack without violating lifo property
#include <stdio.h>
#define MAX 100
int s1[MAX],top1 =-1;
int s2[MAX],top2=-1;
void push1(int x) 
{
    if(top1==MAX-1)
    {
        printf("Stack 1 Overflow\n");
        return;
    }
    s1[++top1]=x;
}
int pop1() 
{
    if(top1==-1) 
    {
        printf("Stack 1 Underflow\n");
        return -1;
    }
    return s1[top1--];
}
void push2(int x) 
{
    if(top2==MAX-1) 
    {
        printf("Stack 2 Overflow\n");
        return;
    }
    s2[++top2]=x;
}
int pop2() 
{
    if(top2==-1) 
    {
        printf("Stack 2 Underflow\n");
        return -1;
    }
    return s2[top2--];
}
void deleteMiddle() 
{
    if(top1==-1) 
    {
        printf("Stack is empty\n");
        return;
    }
    int n=top1+1;
    int mid =n/2;
    for(int i=0;i<mid;i++) 
    {
        push2(pop1());
    }
    int midElem=pop1();
    printf("Deleted middle element: %d\n", midElem);
    while(top2!=-1)
    {
        push1(pop2());
    }
}
void display1() 
{
    if(top1==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack 1:");
    for(int i=top1;i>=0;i--) 
    {
        printf("%d",s1[i]);
    }
    printf("\n");
}
int main() 
{
    int n, x;
    printf("Enter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        printf("Enter element %d:",i+1);
        scanf("%d",&x);
        push1(x);
    }
    display1();
    deleteMiddle();
    display1();
    return 0;
}





// does work but does not follow lifo property and del in o1 time


/*#include<stdio.h>
int stack[100],top=-1;
void push(int x)
{
    if(top==99)
    {
        printf("Stack is full\n");
    }
    else
    {
        stack[++top]=x;
        printf("%d pushed onto stack\n",x);
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d popped from stack\n",stack[top--]);
    }
}
void deleteMiddle()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    int mid=top/2;
    for(int i=mid;i<top;i++)
    {
        stack[i]=stack[i+1];
    }
    top--;
    printf("Middle element deleted from stack\n");
}

void display()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        for(int i=top;i>=0;i--)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        printf("Enter element %d: ",i+1);
        scanf("%d",&x);
        push(x);
    }
    display();
    deleteMiddle();
    display();
    return 0;
}*/