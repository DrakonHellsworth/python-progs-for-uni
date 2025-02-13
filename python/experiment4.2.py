n=int(input("Enter a number:"))
temp=n
s=0
while(n>0):
    r=n%10
    s=s+(r**3)
    n=n//10
if(temp==s):    
    print("Armstrong number")
else:
    print("Not an Armstrong number")