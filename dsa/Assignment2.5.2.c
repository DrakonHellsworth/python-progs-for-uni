//selection sort
#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionsort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        swap(&arr[i],&arr[min]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    selectionsort(arr,n);
    return 0;
}