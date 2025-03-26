//make a program to convert infix expression to prefix expression with the help of stack
/*#include<stdio.h>
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
    if(ch=='^')
        return 3;
    else if(ch=='*'||ch=='/')
        return 2;
    else if(ch=='+'||ch=='-')
        return 1;
    else
        return 0;
}
int main()
{
    char infix[100],prefix[100];
    int i,j=0;
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    for(i=0;infix[i]!='\0';i++)
    {
        if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
            {
                prefix[j++]=pop();
            }
            top--;
        }
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
        {
            while(top!=-1&&stack[top]!='('&&precedence(infix[i])<=precedence(stack[top]))
            {
                prefix[j++]=pop();
            }
            push(infix[i]);
        }
        else
            prefix[j++]=infix[i];
    }
    while(top!=-1)
    {
        prefix[j++]=pop();
    }
    prefix[j]='\0';
    for(i=j-1;i>=0;i--)
    {
        printf("%c",prefix[i]);
    }
    return 0;
}*/
#include<stdio.h>
#include<string.h>
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
void reverse(char *exp) 
{
    int i, len=strlen(exp);
    for(i=0;i<len/2;i++) 
    {
        char temp=exp[i];
        exp[i]=exp[len-i-1];
        exp[len-i-1]=temp;
    }
}
int main() 
{
    char exp[100],prefix[100];
    int i,j=0;
    printf("Enter the infix expression: ");
    scanf("%s",exp);
    reverse(exp);
    for(i=0;exp[i]!='\0'; i++) 
    {
        if(exp[i]=='(') 
            exp[i]=')';
        else if(exp[i]==')') 
            exp[i]='(';
    }
    for(i=0;exp[i]!='\0';i++) 
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')') 
        {
            while(stack[top]!='(') 
            {
                prefix[j++]=pop();
            }
            top--;
        }
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^') 
        {
            while(top!=-1&&precedence(exp[i])<=precedence(stack[top])) 
            {
                prefix[j++]=pop();
            }
            push(exp[i]);
        }
        else 
            prefix[j++] = exp[i];
    }
    while (top!=-1) 
    {
        prefix[j++]=pop();
    }
    prefix[j]='\0';
    reverse(prefix);
    printf("The prefix expression is: %s\n", prefix);
    return 0;
}
