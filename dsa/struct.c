//done
//structure
#include<stdio.h>
int main()
{
    struct student
    {
        char name[20];
        int roll;
        float marks;
    };
    struct student s1;
    printf("Enter name of the student: ");
    scanf("%s",s1.name);
    printf("Enter roll number of the student: ");
    scanf("%d",&s1.roll);
    printf("Enter marks of the student: ");
    scanf("%f",&s1.marks);
    printf("Name of the student: %s\n",s1.name);
    printf("Roll number of the student: %d\n",s1.roll);
    printf("Marks of the student: %f\n",s1.marks);
    return 0;
}