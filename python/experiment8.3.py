#Assume a file city.txt with details of 5 cities in given format (cityname population(in lakhs) area(in sq KM) ):
#Example:
#Dehradun 5.78 308.20
#Delhi 190 1484
#……………
#Open file city.txt and read to:
#a. Display details of all cities
#b. Display city names with population more than 10Lakhs
#c. Display sum of areas of all cities 

file=open("city.txt","r")
for i in file:
    print(i.strip())

file.seek(0)
for i in file:
    if(float(i.split()[1])>10):
        print(i.split()[0])

file.seek(0)
sum=0
for i in file:
    sum+=float(i.split()[2])
print("Sum of areas of all cities is:",sum)
file.close()