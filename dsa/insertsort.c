//done
//insertion sort
#include<stdio.h>
int main()
{
    int i,n,j,k=0;
    printf("Enter the size of the array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:");
    for(i=0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    }
    for(j=1;j<n;j++)
    {
        k=arr[j];
        i=j-1;
        while(i>=0&&arr[i]>k)
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=k;
    }
    printf("The sorted array is:");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}