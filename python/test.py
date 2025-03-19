def dist(rat):
    nc = len(rat)
    cand = [1] * nc

    for i in range(1, nc):
        if rat[i] > rat[i - 1]:
            cand[i] = cand[i - 1] + 1

    for i in range(nc - 2, -1, -1):
        if rat[i] > rat[i + 1]:
            cand[i] = max(cand[i], cand[i + 1] + 1)

    return sum(cand), cand  

ratings = [0,1,2]  
total_candies, distribution = dist(ratings)

print("Total candies needed:", total_candies)
print("Candy distribution:", distribution)