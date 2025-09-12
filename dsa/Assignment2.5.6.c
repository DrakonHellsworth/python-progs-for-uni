//binary search
#include<stdio.h>
void binarySearch(int arr[],int n,int key) 
{
    int low=0,high=n-1,mid;
    while(low<=high) 
    {
        mid=(low+high)/2;
        if(arr[mid]==key) 
        {
            printf("Element found at index %d\n",mid);
            return;
        } 
        else if(arr[mid]<key) 
        {
            low=mid+1;
        } 
        else 
        {
            high=mid-1;
        }
    }
    printf("Element not found\n");
}
int main() 
{
    int n,key;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d",&key);
    binarySearch(arr,n,key);
    return 0;
}