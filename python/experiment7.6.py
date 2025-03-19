#6. Write a lambda function which gives tuple of max and min from a list.
#Sample input: [10, 6, 8, 90, 12, 56]
#Sample output: (90,6)
def max_min(lst):   
    return (max(lst), min(lst))
print(max_min([10, 6, 8, 90, 12, 56]))  
