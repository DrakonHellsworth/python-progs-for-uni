#write a py func that accepts a string and counts the number of upper and lower case letters
def count(string):
    u=0 
    l=0
    sp=0
    for i in string:
        if i.isupper():
            u+=1
        elif i.islower():
            l+=1
        else:
            sp+=1
    return u,l,sp
s=input("Enter a string:")
u,l,sp=count(s)
print("Number of upper case letters:",u)
print("Number of lower case letters:",l)
print("Number of spaces:",sp)
