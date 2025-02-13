a=float(input ("Enter side a:"))
b=float(input ("Enter side b:"))
c=float(input ("Enter side c:"))
s=a+b+c/2
a=(s*(s-a)*(s-b)*(s-c))**0.5
print("Area of triangle:",a)
