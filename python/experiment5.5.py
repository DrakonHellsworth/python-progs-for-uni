s=input("Enter a string:")
s=s.lower()
d={}
for i in s:
    if i in d.keys():
        d[i]+=1
    else:
        d[i]=1
for i in d.keys():
    print(f"{i}{d[i]}")