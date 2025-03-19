//done
//find the median of an array
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    int median;
    if(n%2==0)
    {
        median=(arr[n/2]+arr[n/2-1])/2;
    }
    else
    {
        median=arr[n/2];
    }
    printf("The median is %d",median);
    return 0;
}