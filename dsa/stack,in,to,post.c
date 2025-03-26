// make a program to covert infix expression to postfix expression with the help of stack
#include<stdio.h>
int stack[100],top=-1;
void push(int item)
{
    stack[++top]=item;
}
int pop()
{
    return stack[top--];
}
int precedence(char ch)
{
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/')
        return 2;
    else if(ch=='^')
        return 3;
    else
        return 0;
}
int main()
{
    char exp[100],pos[100];
    int i,j=0;
    printf("Enter the infix expression: ");
    scanf("%s",exp);
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
        {
            while(stack[top]!='(')
            {
                pos[j++]=stack[top--];
            }
            top--;
        }
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^')
        {
            while(top!=-1&&precedence(exp[i])<=precedence(stack[top]))
            {
                pos[j++]=stack[top--];
            }
            push(exp[i]);    
        }
        else
            pos[j++]=exp[i];
    }
    while(top!=-1)
    {
        pos[j++]=stack[top--];
    }
    printf("The postfix expression is: %s",pos);
    return 0;
}