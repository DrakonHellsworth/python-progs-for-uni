s=int(input("Enter the number of students:"))
l=list(map(int,input("Enter the scores:").split()))
print(f"The topper score is {sorted(l)[-1]}")
print(f" Runner-up score is {sorted(l)[-2]}")