s=int(input("Enter seconds:"))
h=int(s/3600)
m=int((s%3600)/60)
r=s%60
print("Hours:",h,"Minutes:",m,"Seconds:",r)
