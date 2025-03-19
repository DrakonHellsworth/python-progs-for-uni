//create a program to convert a string into a number and vice versa example : three hundred = 300
#include <stdio.h>
#include <string.h>
int main()
{
    int num;
    char str[10];
    printf("Enter a number: ");
    scanf("%d", &num);
    sprintf(str, "%d", num);
    printf("The string representation of %d is: %s\n", num, str);
    return 0;
}