//done
//linear search
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array");
    scanf("%d",&n);
    int arr[n],i,p=0;
    printf("Enter the elements of the array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched");
    scanf("%d",&p);
    for(i=0;i<n;i++)
    {
        if(arr[i]==p)
        {
            printf("The element is found at %d",i+1);
            break;
        }
    }
}