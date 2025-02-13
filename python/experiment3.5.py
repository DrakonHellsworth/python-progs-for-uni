import math
a=float(input("Enter the value of a: "))
b=float(input("Enter the value of b: "))
c=float(input("Enter the value of c: "))
d=b**2-4*a*c
if d>0:
    r1=(-b+math.sqrt(d))/(2*a)
    r2=(-b-math.sqrt(d))/(2*a)
    print("The equation has two real roots:", r1, "and", r2)
elif d==0:
    r=-b/(2*a)
    print("The equation has one real root:", r)
else:
    real=-b/(2*a)
    imag=math.sqrt(-d)/(2*a)
    print("The equation has two complex roots:", complex(real,imag),"and", complex(real,-imag))