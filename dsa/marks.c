//DONE
//define structure of students having data members name, address and marks in Clanguage , marks in information technology,take data for n students in an array dynamically and find the total mars of 10
#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[20];
    char address[20];
    int clanguage;
    int it;
};
int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n); 
    struct student *s=(struct student*)malloc(n*sizeof(struct student));
    for(int i=0;i<n;i++)
    {
        printf("Enter name of student %d: ",i+1);
        scanf("%s",s[i].name);
        printf("Enter address of student %d: ",i+1);    
        scanf("%s",s[i].address);    
        printf("Enter marks in clanguage of student %d: ",i+1);    
        scanf("%d",&s[i].clanguage);    
        printf("Enter marks in information technology of student %d: ",i+1);    
        scanf("%d",&s[i].it);    
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+s[i].clanguage+s[i].it;    
    }
    printf("Total marks of %d students: %d\n",n,sum); 
    free(s);
    return 0;
}