while True:
    try:
        height = int(input("Height of pyramid: "))
        if 1 <= height < 9:
            break
        else:
            print("The height should be between 1 and 8.")
    except ValueError:
        print("A number, please.")

for i in range(height):
    print(" " * (height - i - 1), end="")
    print("#" * (i + 1), end="")
    print("  ", end="")
    print("#" * (i + 1))
