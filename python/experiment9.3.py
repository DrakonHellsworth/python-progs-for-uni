#. Create programs to implement different types of inheritances. 

class A:
    def __init__(self):
        self.a=10
class B(A):
    def __init__(self):
        super().__init__()
        self.b=20
class C(B):
    def __init__(self):
        super().__init__()
        self.c=30    
    def display(self):
        print(self.a)
        print(self.b)
        print(self.c)    
c=C()
c.display()     