//'WAP a C Program to Reverse an array using Stack
#include<stdio.h>
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
int main()
{
    int n;
    printf("Enter the number of elements to be entered in the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        push(arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        pop();
    }
    return 0;
}