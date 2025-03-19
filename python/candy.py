# there are n children standing in a line each child is assigned a rating value given in the integer array ratings. you are giving candies to these children subjected to the following requirements: each child must have atleast one candy. each child does not receive more candies than their sibling in the line to their left. write a function to return the minimum number of candies you need to give.
def candy(ratings):
    n=len(ratings)
    candies=[1]*n
    for i in range(1,n):
        if ratings[i]>ratings[i-1]:
            candies[i]=candies[i-1]+1
    for i in range(n-2,-1,-1):
        if ratings[i]>ratings[i+1]:
            candies[i]=max(candies[i],candies[i+1]+1)
    return sum(candies)
rating=[]
c=int(input("Enter the number of children: "))
for i in range(1,c+1):
    r=int(input("Enter the ratings: "))
    rating.append(r)
print(candy(rating))