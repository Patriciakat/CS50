from cs50 import get_int

while True:
    height = get_int("Enter pyramid's height: ")
    if height > 8:
        print("Enter number smaller than 8")
    elif height < 1:
        print("Enter positive number")
    else: break

for i in range(height):
    for j in range(height - i):
        print(" ", end="")
    for j in range(i+1):
        print("#", end="")
    print("  ", end="")
    for j in range(i+1):
        print("#", end="")
    print()