//done

//create a stack with an array and perform push pop and display on it
#include <stdio.h>
int top=-1;
int stack[100];
void push(int x)
{
    if(top<99)
    {
        top=top+1;
        stack[top]=x;
    }
    else
    {
        printf("stack overflow\n");
    }
}
void pop()
{
    if(top>=0)
    {
        top=top-1;
    }
    else
    {
        printf("stack underflow\n");
    }
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}
int main()
{
    int value;  
    printf("Enter the number of elements: ");
    scanf("%d",&value);
    for(int i=0;i<value;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&stack[i]);
    }
    top=value-1;
    display();
    pop();
    display();
    printf("Enter the push value: ");
    scanf("%d",&value);
    push(value);
    display();
    return 0;
}