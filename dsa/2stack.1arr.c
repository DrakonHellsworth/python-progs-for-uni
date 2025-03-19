//Create two stack in a single array
#include <stdio.h>
int stack[100];
int top1=-1;
int top2=100;  
void push1(int x)
{
    if(top1+1<top2)
    {
        top1++;
        stack[top1]=x;
    }
    else
    {
        printf("Stack overflow for stack1\n");
    }
}
void push2(int x)
{
    if(top2-1>top1)
    {
        top2--;
        stack[top2]=x;
    }
    else
    {
        printf("Stack overflow for stack2\n");
    }
}
void display1()
{
    int i;
    printf("Stack 1:\n");
    for(i=top1;i>=0;i--)
    {
        printf("%d\n", stack[i]);
    }
}
void display2()
{
    int i;
    printf("Stack 2:\n");
    for(i=top2;i<100;i++)
    {
        printf("%d\n",stack[i]);
    }
}
int main()
{
    int n1, n2, d;
    printf("Enter the number of elements to push into stack1: ");
    scanf("%d", &n1);
    for(int i=0;i<n1;i++)
    {
        printf("Enter element for stack1, number %d: ",i+1);
        scanf("%d",&d);
        push1(d);
    }
    printf("Enter the number of elements to push into stack2: ");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
    {
        printf("Enter element for stack2, number %d: ",i+1);
        scanf("%d", &d);
        push2(d);
    }
    display1();
    display2();
    return 0;
}
