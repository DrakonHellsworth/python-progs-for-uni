//create a code to print this pattern-
//A
//b C
//D e F
//g H i J
#include <stdio.h>
int main() 
{
    printf("Enter the number of rows: ");
    int i,l;
    scanf("%d",&l); 
    int j,k=65,n=1;
    for(i=1;i<=l;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(i==1 || i%2==0)
            {
            if(n%2==0)
            {
                printf("%c ",(k+32));
            }
            else
            printf("%c ",k);
            }
            else
            {
                if(n%2!=0)
                printf("%c ",k+32);
                else
                printf("%c ",k);
            }
        n++;
        k++;
        }
        printf("\n");
    }
    return 0;
}