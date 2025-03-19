//done
//multiply two matrices
#include<stdio.h>
int main()
{
    int m1,n1,m2,n2,i,j,k;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%dx%d",&m1,&n1);
    int a[m1][n1];
    printf("Enter the elements of the first matrix: \n");
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
        printf("A[%d][%d] = ",i+1,j+1);    
        scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%dx%d",&m2,&n2);
    int b[m2][n2];
    printf("Enter the elements of the second matrix: \n");
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
        printf("B[%d][%d] = ",i+1,j+1);
        scanf("%d",&b[i][j]);
        }
    }
    if(n1!=m2)
    {
    printf("Matrices cannot be multiplied.\n");
    return 0;
    }
    int c[m1][n2];
    for(i=0;i<m1;i++)
    {
    for(j=0;j<n2;j++)
        {
        c[i][j]=0;
        for(k=0;k<n1;k++)
        {
            c[i][j]+=a[i][k]*b[k][j];
        }
        }
    }
    printf("\nThe product of the matrices is:\n ");
    for(i=0;i<m1;i++)
    {
        printf("\n\n");
        for(j=0;j<n2;j++)
        {
            printf("%d  ",c[i][j]);
        }
    }
    return 0;
}