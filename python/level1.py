#a function to take an array of string and returns the longest common prefix string
def longest(strs):
    if not strs:
        return ""
    prefix=strs[0]
    for i in range(1,len(strs)):
        while strs[i].find(prefix)!=0:
            prefix=prefix[:-1]
            if not prefix:   
                return ""
    return prefix
n=int(input("Enter the number of strings: "))
strs=[]
for i in range(n):
    s=input("Enter the string: ")
    strs.append(s)
print(f"The longest common prefix is: {longest(strs)}")