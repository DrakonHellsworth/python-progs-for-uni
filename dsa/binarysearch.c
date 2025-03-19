//done
//binary search
#include <stdio.h>
int main()
{
    int a[10],i,n,k,l=0,h,m;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    h=n-1;
    printf("Enter the element to be searched\n");
    scanf("%d",&k);
    while(l<=h)
    {
        m=(l+h)/2;
        if(k==a[m])
        {
            printf("Element found at position %d\n",m+1);
            break;
        }
        else if(k<a[m])
        {
            h=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    if(l>h)
    {
        printf("Element not found\n");
    }
    return 0;
}
