n=input("Enter a string:")
c=0
for i in n:
    if i.isupper():
        c+=1
print("Number of capital letters:",c) 