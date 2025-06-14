


menu = {
    "Baja Taco": 4.25,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

orderlist = []
Total = 0
i = 0
while True:
    try:
        item = input("Item: ").title()
        if len(item) > 0 :
            if item in menu:
                orderlist.append(item)
                for order in orderlist[i:]:
                    Total += menu[order]
                    print(f"Total: ${Total:.2f}")

                i = len(orderlist)

    except EOFError:
        print("")
        break




