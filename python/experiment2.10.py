print("A\tB\tA&B\tA|B\tA^B")
print("-"*35)
for A in [0,1]:
    for B in [0,1]:
        and_result=A&B
        or_result=A|B
        xor_result=A^B
        print(f"{A}\t{B}\t{and_result}\t{or_result}\t{xor_result}")


