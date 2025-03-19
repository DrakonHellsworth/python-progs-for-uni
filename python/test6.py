#find the unique triplets in a given array whose sum is 0
def findTriplets(arr, n):
    arr.sort()
    a=[]
    for i in range(n):
        for j in range(i,n):
            for k in range(j,n):
                if arr[i]+arr[j]+arr[k]==0:
                    a.append([arr[i],arr[j],arr[k]])
                    return a
n=int(input(print("Enter the number of inputs")))
arr=[int(input("Enter the elements: "))for i in range(n)]
print(f"the triplets are {findTriplets(arr,n)}")