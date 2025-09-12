//WAP a C Program to reverse the stack using the queue data structure.
#include<stdio.h>
int stack[100],top=-1;
int q[100],f=-1,r=-1;
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
void enqueue(int x)
{
    if(r==99)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(f==-1)
        {
            f=0;
        }
        q[++r]=x;
        printf("%d enqueued to queue\n",x);
    }
}
void dequeue()
{
    if(f==r)
    {
        printf("Queue is empty\n");
    }
    else
    {
        f++;
        printf("%d dequeued from queue\n",q[f]);
    }
}
void reverseStack()
{
    while(top!=-1)
    {
        enqueue(stack[top]);
        pop();
    }
    while(f!=r)
    {
        dequeue();
        push(q[f]);
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
    reverseStack();
    printf("Stack after reversing:\n");
    for(int i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
    return 0;
}