//stable sort for count sort
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
    for(int i=1;i<=max;i++) 
    {
        c[i]=c[i]+c[i-1];
    }
    int b[n];
    for(int i=n-1;i>=0;i--) 
    {
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
    printf("Sorted array: ");
    for(int i=0;i<n;i++) 
    {
        printf("%d ",b[i]);
    }
    printf("\n");
return 0;
}