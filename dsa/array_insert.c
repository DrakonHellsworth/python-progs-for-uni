//DONE
// to insert an element in an array
#include<stdio.h>
int main()
{
    int n,i,k,temp1,temp2,p;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array");
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    printf("Enter the number to be inserted in the array:");
    scanf("%d",&k);
    printf("Enter the position to be inserted in the array;");
    scanf("%d",&p);
    for(i=p-1;i<n+1;i++)
    {
        temp1=a[i];
        if(i==p-1)
        {
        a[i]=k;
        temp2=a[i+1];
        a[i+1]=temp1;
        }
        else{
        temp1=temp2;
        temp2=a[i+1];
        a[i+1]=temp1;
        }
    }
    printf("The new array will be:");
    for(i=0;i<n+1;i++)
    {
        printf("%d ",a[i]);
    }
}