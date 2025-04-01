//create a program to find the factorial of a number using recursion and iteration give choice of method to user
#include<time.h>
#include <stdio.h>
int fact(int n)
{
    if (n==0)
        return 1;
    else
        return n*fact(n-1);
}
int main()
{
    long double n,c;
    clock_t start,end;
    double t1,t2;
    printf("Enter a number to find its factorial: ");
    scanf("%lf",&n);
    printf("Enter 1 for recursion or 2 for iteration: ");
    scanf("%lf",&c);
    if(c==1)
    {
    start=clock();
        printf("Factorial of %lf is %d\n",n,fact(n));
    end=clock();
    t1=(double)(end-start);
    t2=t1/CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n",t2);
    }
    else if(c==2)
    {
        start=clock();
        {
        int i,r=1;
        for (i=1;i<=n;i++)
            r*=i;
        printf("Factorial of %lf is %d\n",n,r);
        }
        end=clock();
        t1=(double)(end-start);
        t2=t1/CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n",t2);
    }
    else
    {
        printf("Invalid choice\n"); 
    }
return 0;
}