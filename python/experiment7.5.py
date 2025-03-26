#Write a lambda function to find volume of cone. 
v=(lambda r,h:3.14*r*r*h/3)
r=int(input("Enter the radius: "))
h=int(input("Enter the height: "))
print("Volume of cone:",v(r,h))  