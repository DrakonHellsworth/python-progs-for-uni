//Write a C program to evaluate a given postfix expression using a stack. The postfix expression contains only integers and the following operators: '+, -, "*, and '/".
// The program should read the postfix expression from the user, evaluate it, and print the result.
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
    int i,j=0;
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
            int a=pop();
            int b=pop();
            if(exp[i]=='+')
            {
                push(a+b);
            }
            else if(exp[i]=='-')
            {
                push(b-a);
            }
            else if(exp[i]=='*')
            {
                push(a*b);
            }
            else if(exp[i]=='/')
            {
                push(b/a);
            }
        }
    }
    printf("The result is: %d",pop());
}