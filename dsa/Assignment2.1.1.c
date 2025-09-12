//Write a program to perform the following tasks: 
// a. Push 7 elements onto the stack. 
// b. Print the top element. 
// c. Pop 2 elements from the stack. 
// d. Print the top element after popping. 
// e. Check if the stack is empty. 
// f. Check if the stack is full.
#include <stdio.h>
int stack[100], top = -1;
void push(int x) 
{
    if(top==99)
    {
        printf("Stack is full\n");
    }
    else
    {
        stack[++top] = x;
        printf("%d pushed onto stack\n", x);
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
        printf("%d popped from stack\n", stack[top--]);
    }
}
void peek() 
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element is %d\n", stack[top]);
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
        printf("Enter element %d:",i+1);
        scanf("%d", &x);
        push(x);
    }
    peek();
    pop();
    pop();
    peek();
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
    if(top==99)
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Stack is not full\n");
    }
    return 0;
}