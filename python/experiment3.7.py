d=int(input("Enter day:"))
m=int(input("Enter month:"))
y=int(input("Enter year:"))
if m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12:
    if d==31:
        d=1
        m=m+1
    else:
        d=d+1
elif m==4 or m==6 or m==9 or m==11: 
    if d==30:
        d=1
        m=m+1
    else:
        d=d+1
elif m==2:
    if y%4==0:
        if d==29:
            d=1
            m=m+1
        else:
            d=d+1
    else:
        if d==28:
            d=1
            m=m+1
        else:
            d=d+1
print("Day:",d,"Month:",m,"Year:",y)