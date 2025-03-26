# Write functions to explain mentioned concepts:
#a. Keyword argument
#b. Default argument
#c. Variable length argument 
def info(name,age):
    print(f"Student Name:{name}")
    print(f"Student Age:{age}")
info(age=20,name="ME")
def greet(name="MaGustastu"):
    print(f"Hello,{name}!")
greet("Anmol")
greet()
def add(*a):
    tot=sum(a)
    print(f"Sum:{tot}")
add(1,2,3,4,5)