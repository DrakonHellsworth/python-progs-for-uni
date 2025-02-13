//define a structure of employee having data members name,address,age and salary,take data for an employee in an array dynamically and fing the avg salary
#include<stdio.h>
#include<stdlib.h>
struct employee
{
    char name[20];
    char address[20];
    int age;
    float salary;
};
struct employee *ptr;
int main()
{
    int n,i;
    printf("Enter the number of employees: ");
    scanf("%d",&n);
    ptr=(struct employee*)malloc(n*sizeof(struct employee));
    for(i=0;i<n;i++)
    {
        printf("Enter the name of employee %d: ",i+1);
        scanf("%s",ptr[i].name);
        printf("Enter the address of employee %d: ",i+1);    
        scanf("%s",ptr[i].address);
        printf("Enter the age of employee %d: ",i+1);
        scanf("%d",&ptr[i].age);
        printf("Enter the salary of employee %d: ",i+1);
        scanf("%f",&ptr[i].salary);
    }
    float sum=0;
    for(i=0;i<n;i++)
    {
        sum+=ptr[i].salary;
    }
    float avg=sum/n;
    printf("The average salary of the employees is %f",avg);
    free(ptr);
    return 0;
}


