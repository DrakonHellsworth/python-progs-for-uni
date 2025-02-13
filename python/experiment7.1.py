#Write a Python function to find the maximum and minimum numbers from a sequence of numbers. (Note: Do not use built-in functions.) 
def find_max_min(n):
    max=n[0]
    min=n[0]
    for num in n:
        if num>max:
            max=num
        if num<min:    
            min=num
    return max,min
n=int(input("Enter the number of elements: "))
numb=[]
for i in range(n):
    num=int(input(f"Enter element {i+1}: "))
    numb.append(num)
max,min=find_max_min(numb)
print(f"The maximum number is {max} and the minimum number is {min}")   
