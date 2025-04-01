#Add constructor in the above class to initialize student details of n students and
#implement following methods:
#a) Display() student details
#b) Find Marks_percentage() of each student
#c) Display result() [Note: if marks in each subject >40% than Pass else Fail]
#Write a Function to find average of the class.
class std:
    def __init__(self,name,sapid,phy,chem,maths):
        self.name=name
        self.sapid=sapid    
        self.phy=phy
        self.chem=chem
        self.maths=maths
    def display(self):
        print("Name:",self.name)
        print("SAPID:",self.sapid)
        print("Physics:",self.phy)
        print("Chemistry:",self.chem)
        print("Maths:",self.maths)    
    def per(self):
        return (self.phy+self.chem+self.maths)/3
    def result(self):
        if self.perc()>40:
            print("Pass")
        else:
            print("Fail")
    def avg(stds):
        total=0
        for i in stds:
            total+=stds.per()
        return total/len(stds)

#main program
n=int(input("Enter number of students: "))
stds=[]
for i in range(n):
    name=input("Enter name: ")
    sapid=int(input("Enter SAPID: "))
    phy=float(input("Enter Physics marks: "))
    chem=float(input("Enter Chemistry marks: "))
    maths=float(input("Enter Maths marks: "))
    std=std(name,sapid,phy,chem,maths)
    stds.append(std)
for std in stds:
    std.display()    
    std.result()
    print("Marks Percentage:",std.perc())
print("Average marks of class:",std.avg(stds))