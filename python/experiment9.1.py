# without instructor make-1.Create a class of student (name, sap id, marks[phy,chem,maths] ). Create 3 objects by taking inputs from the user and display details of all students. 
class Student:
    def __init__(self,name,sapid,phy,chem,maths):
        self.name=name
        self.sapid=sapid
        self.phy=phy
        self.chem=chem
        self.maths=maths
    def details(self):
        print(f"name:{self.name},SAPID:{self.sapid},marks:{self.phy},{self.chem},{self.maths}")
stds=[]
i=0
for i in range(3):
    name=input("Enter name: ")
    sapid=input("Enter SAP ID: ")
    phy=float(input("Enter Physics marks: "))
    chem=float(input("Enter Chemistry marks: "))
    maths=float(input("Enter Maths marks: "))
    std = Student(name,sapid,phy,chem,maths)
    stds.append(std)
for student in stds:
    student.details()
