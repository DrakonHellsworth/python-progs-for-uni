//DONE
// program to create a dynamic array
#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int *arr;
    int s;
    printf("Enter the size of the array: ");
    scanf("%d",&s);
    arr=(int*)malloc(s*sizeof(int));
    for (int i=0;i<s;i++) 
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Array elements are: ");
    for (int i=0;i<s;i++) 
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
