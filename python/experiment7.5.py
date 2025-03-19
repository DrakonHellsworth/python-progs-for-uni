#Write a lambda function to find volume of cone. 
def find_volume(radius, height):
    volume = lambda radius, height: (22/7)*radius*radius*height/3
    return volume(radius, height)
print(find_volume(5, 10))  