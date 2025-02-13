n=input("Enter a string:")
count=0
for i in n:    
    if(i=='a' or i=='e' or i=='i' or i=='o' or i=='u'):
        count=count+1
print("Total number of vowels in the string is:",count)
