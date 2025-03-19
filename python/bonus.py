def remove(arr,n):
    a=0
    for i in range(len(arr)):
        if arr[i]!=n:
            arr[a]=arr[i]
            a+=1
    return a
arr=[int(x) for x in input("Enter the elements of the array separated by space: ").split()]
n=int(input("Enter the value to remove: "))
a=remove(arr,n)
print(f"Number of elements not equal to {n} is:{a}")
print(f"Modified array : {arr[:a]}") 