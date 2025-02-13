num=int(input("Enter a number:"))
shift=int(input("Enter shift value:"))
left=num<<shift
right=num>>shift
print(f"Left shift of {num} by {shift} positions is {left}")
print(f"Right shift of {num} by {shift} positions is {right}")