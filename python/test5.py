#find the longest increasing subsequence in a given list of numbers
def longest(arr):
    if not arr:
        return []
    max=[arr[0]]
    curr=[arr[0]]
    for i in range(1,len(arr)):
        if arr[i]==arr[i-1]+1:
            curr.append(arr[i])
        else:
            if len(curr)>len(max):
                max=curr
            curr=[arr[i]]
    if len(curr)>len(max):
        max=curr
    return max
n=int(input("Enter number of elements: "))
arr=[int(input("Enter the element: ")) for i in range(n)]
print("Longest increasing subsequence:",longest(arr))