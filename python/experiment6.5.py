n=int(input("Enter the number of movies: "))
d={}
for i in range(n):
    n=input("Enter the name of the movie: ")
    y=int(input("Enter the year of release: "))
    d=input("Enter the name of the director: ")
    c=int(input("Enter the production cost: "))
    e=int(input("Enter the collection made: "))
    d[n]=[y,d,c,e]
print("Name\tYear\tDirector\tProduction Cost\tEarning")
for i in d.keys():    
    print(f"{i}\t{d[i][0]}\t{d[i][1]}\t{d[i][2]}\t{d[i][3]}")
print("Movies released before 2015:")
for i in d.keys():
    if d[i][0]<2015:
        print(i)
print("Movies that made a profit:")
for i in d.keys():
    if d[i][3]>d[i][2]:
        print(i)