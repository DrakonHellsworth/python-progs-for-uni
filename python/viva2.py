def split(arr):
    total=sum(arr)
    left=0
    for i in range(len(arr)):
        left+=arr[i]
        right=total-left
        if left==right:
            return "true"
    return "false"

x=int(input("Enter number of elements: "))
arr=[]
for i in range(x):
    y=int(input("Enter element"))
    arr.append(y)
print(split(arr))