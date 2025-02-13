//done
// find the number of duplicate elements
#include <stdio.h>
int main() 
{
    int n,i,j,count=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++) 
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++) 
    {
        for(j=i+1;j<n;j++) 
        {
            if(arr[i]==arr[j]) 
            {
                count++;
            }
        }
    }
    printf("Number of duplicate elements: %d",count);
return 0;
}