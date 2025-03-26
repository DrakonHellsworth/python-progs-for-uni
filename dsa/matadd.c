//DONE
//addition of two matrices
#include<stdio.h>
int main()
{   int m1,n1,i,m2,n2,j;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d",&m1,&n1);
    int a[m1][n1];
    printf("Enter the elements of the first matrix:\n");
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            printf("Enter element A[%d][%d]: ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d",&m2,&n2);
    int b[m2][n2];
    printf("Enter the elements of the second matrix:\n");
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
            printf("Enter element B[%d][%d]: ",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }
    if(m1!=m2||n1!=n2)
    {
        printf("Matrices cannot be added.\n");
        return 0;
    }
    int c[m1][n1];
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    printf("matrix A:\n\n");
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n\n");
    }
    printf("matrix B:\n\n");
    for(i=0;i<m2;i++)
    {
        for(int j=0;j<n2;j++)
        {
            printf("%d ",b[i][j]); 
        }
        printf("\n\n");
    }
    printf("Sum of the matrices:\n\n");
    for(i=0;i<m1;i++)
    {
        for(int j=0;j<n1;j++)
        {
            printf("%d  ",c[i][j]);
        }
        printf("\n\n");
    }
    return 0;
}