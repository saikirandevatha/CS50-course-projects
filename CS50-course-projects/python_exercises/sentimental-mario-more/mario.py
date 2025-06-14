# TODO
while True:
    try:
        height = int(input("Height: "))
        if height >= 1 and height <= 8:
            for i in range(height):
                print(" " * (height - i - 1) + "#" * (i + 1), "", "#" * (i + 1))
            break
    except ValueError:
        None
        # print("Enter a positive integer between 1 and 8")
