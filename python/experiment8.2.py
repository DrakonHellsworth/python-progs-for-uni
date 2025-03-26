#Store integers in a file.
#a. Find the max number
#b. Find average of all numbers
#c. Count number of numbers greater than 100 
f=open("number.txt","w")
f.write("10\n")
f.write("20\n")
f.write("30\n")
f.write("40\n")
f.write("50\n")
f.write("150\n")
f.close()

f=open("number.txt","r")
max=0
sum=0
c=0
for i in f:
    i=int(i)
    if(i>max):
        max=i
    sum=sum+i
    if(i>100):
        c=c+1
print("Maximum number in the file is:",max)
print("Average of all numbers in the file is:",sum/6)
print("Number of numbers greater than 100 in the file is:",c)
f.close()
