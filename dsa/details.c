//done
#include<stdio.h>
struct date
{
    int day;
    int month;
    int year;
};
struct employee
{
    int id;
    char name[20];
    float salary;
    struct date da;
} em;
int main()
{
    printf("Enter employee id: ");
    scanf("%d",&em.id);
    printf("Enter employee name: ");
    scanf("%s",em.name);
    printf("Enter employee salary: ");
    scanf("%f",&em.salary); 
    printf("Enter employee date of joining: ");
    scanf("%d %d %d",&em.da.day,&em.da.month,&em.da.year);
    printf("Employee id: %d\n",em.id);
    printf("Employee name: %s\n",em.name);
    printf("Employee salary: %f\n",em.salary);
    printf("Employee date of joining: %d %d %d\n",em.da.day,em.da.month,em.da.year);
    return 0;
}