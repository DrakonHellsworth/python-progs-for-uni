#Create a class to implement method Overriding. 
class A:
    def show(self):
        print("Class A")
class B(A):
    def show(self):
        print("Class B")
b=B()
b.show()