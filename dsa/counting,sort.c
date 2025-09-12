//create a program of count sort
#include <stdio.h>
int main() 
{
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&a[i]);
    }
    int max=a[0];
    for(int i=1;i<n;i++) 
    {
        if(a[i]>max) 
        {
            max=a[i];
        }
    }
    int c[max+1];
    for(int i=0;i<=max;i++) 
    {
        c[i]=0;
    }
    for(int i=0;i<n;i++) 
    {
        c[a[i]]++;
    }
    printf("Sorted array: ");
    for(int i=0;i<=max;i++) 
    {
        for(int j=0;j<c[i];j++) 
        {
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}
