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
for line in file:
    print(line.strip())
    if float(line.split()[1])>10:
        print(line.split()[0])
sum=0
for line in file:
    sum+=float(line.split()[2])
print(sum)
