//done
// make an code for deleting an element in an array
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n],i;
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the position of the element to be deleted: ");
    scanf("%d",&i);
    for(int j=i-1;j<n-1;j++)    
    {
        arr[j]=arr[j+1];
    }
    printf("The new array is: ");
    for(i=0;i<n-1;i++)
    {
        printf("%d ",arr[i]);
    }
return 0;
}