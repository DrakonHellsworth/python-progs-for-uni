#Add few names, one name in each row, in “name.txt file”.
#a. Count no of names
#b. Count all names starting with vowel
#c. Find longest name 

f=open("name.txt","w")
f.write("Anmol Thapliyal\n")
f.write("Anu Thapliyal\n")
f.write("Thapliyal\n")
f.close()
f=open("name.txt","r")
count=0
for i in f:
    count=count+1
print("Total number of names in the file is:",count)    
f.close()
f=open("name.txt","r")
count=0
for i in f:     
    if(i[0]=='a'or i[0]=='e'or i[0]=='i'or i[0]=='o'or i[0]=='u'or i[0]=='A'or i[0]=='E'or i[0]=='I'or i[0]=='O'or i[0]=='U'):
        count=count+1
print("Total number of names starting with vowels is:",count)    
f.close()
f=open("name.txt","r")
max=0
for i in f:
    if(len(i)>max):
        max=len(i)
print("Longest name is:",max,"characters long")    
f.close()

