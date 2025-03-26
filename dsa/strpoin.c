//pointer to structure
#include <stdio.h>
struct student 
{
   char name[20];
   int roll;
   float marks;
};
int main() 
{
   struct student s1; 
   struct student *ptr=&s1; 
   printf("Enter name of the student: ");
   scanf("%s", ptr->name);
   printf("Enter roll number of the student: ");
   scanf("%d", &ptr->roll);
   printf("Enter marks of the student: ");
   scanf("%f", &ptr->marks);
   printf("Name of the student: %s\n", ptr->name);
   printf("Roll number of the student: %d\n", ptr->roll);
   printf("Marks of the student: %f\n", ptr->marks);
   return 0;
}
