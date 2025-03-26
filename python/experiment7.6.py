#6. Write a lambda function which gives tuple of max and min from a list.
#Sample input: [10, 6, 8, 90, 12, 56]
#Sample output: (90,6)
mm=(lambda x: (max(x),min(x)))
x=tuple(int(i) for i in input("Enter elements: ").split(sep=','))
print(mm(x))