# Write functions to explain mentioned concepts:
#a. Keyword argument
#b. Default argument
#c. Variable length argument 
def student_info(name,age):
    print(f"Student Name:{name}")
    print(f"Student Age:{age}")
student_info(age=20,name="ME")
def greet(name="MaGustastu"):
    print(f"Hello,{name}!")
greet("Anmol")
greet()
def add_numbers(*args):
    total=sum(args)
    print(f"Sum:{total}")
add_numbers(101,0,201)