#. Create programs to implement different types of inheritances. 
class A:  # BASE CLASS
    def __init__(self,name,sapid):
        self.name=name
        self.sapid=sapid
    def display(self):
        print("Name:",self.name)
        print("SAP ID:",self.sapid)

class B(A):  # SINGLE LEVEL
    def __init__(self,name,sapid,phy,chem,maths):
        super().__init__(name,sapid)
        self.phy=phy
        self.chem=chem
        self.maths=maths

class C(B):  # MULTILEVEL
    def __init__(self,name,sapid,phy,chem,maths):
        super().__init__(name,sapid,phy,chem,maths)
    def per(self):
        return (self.phy+self.chem+self.maths)/3
    def result(self):
        if self.phy>40 and self.chem>40 and self.maths>40:
            print("Result: Pass")
        else:
            print("Result: Fail")

class E(A):  # HIERARCHICAL
    def __init__(self, name,sapid,sports):
        super().__init__(name,sapid)
        self.sports=sports

    def show_sports(self):
        print("Sports Marks:",self.sports)

class D(C,E):  # MULTIPLE
    def __init__(self,name,sapid,phy,chem,maths,sports):
        C.__init__(self,name,sapid,phy,chem,maths)
        E.__init__(self,name,sapid,sports)

    def dis(self):
        self.display()
        print("Physics:",self.phy)
        print("Chemistry:",self.chem)
        print("Maths:",self.maths)
        print("Sports Marks:",self.sports)
        print("Percentage:",self.per())
        self.result()

class Hybrid:  # HYBRID CLASS 
    def __init__(self,students):
        self.students=students
    def avg(self):
        total=sum(s.per() for s in self.students)
        return total/len(self.students)
    def dis(self):
        print("Class Average Marks:",self.avg())

n=int(input("Enter number of students: "))
students=[]
for i in range(n):
    name=input("Enter name: ")
    sapid=int(input("Enter SAP ID: "))
    phy=float(input("Enter Physics marks: "))
    chem=float(input("Enter Chemistry marks: "))
    maths=float(input("Enter Maths marks: "))
    sport=float(input("Enter Sports marks: "))

    student=D(name,sapid,phy,chem,maths,sport)
    students.append(student)

print("\n--- Student Details ---")
for s in students:
    s.dis()
    print()

hybrid=Hybrid(students)
hybrid.dis()
