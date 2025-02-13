d={}
n=int(input("Enter number of students: "))
for i in range(n):
    name=input("Enter name: ")
    city=input("Enter city: ")
    d[name]=city
print(d)
print("a) Display all names: ",list(d.keys()))
print("b) Display all city names: ",list(d.values()))
print("c) Display student name and city of all students: ",d.items())
print("d) Count number of students in each city: ",len(d))