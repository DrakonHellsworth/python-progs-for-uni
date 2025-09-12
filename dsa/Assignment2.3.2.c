//Write a program to read a postfix expression from the user, evaluate it using a stack, and print the result.
#include<stdio.h>
int stack[100],top=-1;
void push(int x)
{
    stack[++top]=x;
}
int pop()
{
    return stack[top--];
}
int main()
{
    char exp[100];
    int i;
    printf("Enter the postfix expression: ");
    scanf("%s",exp);
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]>='0'&&exp[i]<='9')
        {
            push(exp[i]-'0');
        }
        else
        {
            int b=pop();
            int a=pop();
            if(exp[i]=='+')
            {
                push(a+b);
            }
            else if(exp[i]=='-')
            {
                push(a-b);
            }
            else if(exp[i]=='*')
            {
                push(a*b);
            }
            else if(exp[i]=='/')
            {
                push(a/b);
            }
        }
    }
    printf("The result is: %d",pop());
    return 0;
}