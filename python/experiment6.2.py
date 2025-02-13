n=int(input("Enter the size of the tuple:"))
i=0
t=()
while(i<n):
    i=i+1
    t=t+(int(input("Enter the number:")),)
    print("Tuple is:",t)
print(f"Average of the tuple is:{sum(t)/len(t)}")