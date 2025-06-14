class Jar:
    def __init__(self, capacity=12):
        self._size=0
        if capacity < 1:
            raise ValueError("Size cannot be negative")

        self._capacity=capacity

    def __str__(self):
        returntext = f"Jar size is {self._size} "
        returntext += "🍪" * self._size  # Add cookies for the filled size
        returntext += "_" * (self._capacity - self._size)  # Add placeholders for the empty capacity
        # returntext += " Capacity is "
        # returntext += "🍪" * self._capacity
        return returntext

    def deposit(self, n):
        if n<1:
            raise ValueError("Size cannot be less than 1")
        elif self._size + n > self._capacity:
            raise ValueError("Not enough capacity")
        else:
            self._size += n


    def withdraw(self, n):
        if n<1:
            raise ValueError("Minimum 1 cookie should be withdrawn")
        elif self._size - n < 0:
            raise ValueError("Not enough cookies to withdraw")
        else:
            self._size -= n


    @property
    def capacity(self):
        return self._capacity



    @property
    def size(self):
        return self._size




while True:
    try:
        maxcapacity=int(input("Enter maximum capacity of the jar: "))
        jar= Jar(maxcapacity)
        print(jar)
        break

    except ValueError:
        print("invalid capacity entered, enter again")


while True:
    question = input("would you like to deposit or withdraw, enter D or W: ")
    if question.lower() == 'd':
        while True:
            try:
                cookiedeposit = int(input("How many cookies would you like to deposit? "))
                jar.deposit(cookiedeposit)
                print(jar)
                break

            except ValueError as e:
                print(jar)
                if "Not enough capacity" in str(e):
                    print("Not enough capacity")
                else:
                    print("Invalid deposit entry")
                    continue

    elif question.lower() == 'w':
        while True:
            try:
                cookiewithdraw = int(input("How many cookies would you like to withdraw? "))
                jar.withdraw(cookiewithdraw)
                print(jar)
                break

            except ValueError as e:
                print(jar)
                if "Not enough cookies to withdraw" in str(e):
                    print ("Not enough cookies to withdraw")
                else:
                    print ("Invalid withdraw entry")
                    continue
    else:
        print("Invalid entry, try again")
        continue

    if jar.size <1:
        break

print("zero cookies left")






#         __init__ should initialize a cookie jar with the given capacity, which represents the maximum number of cookies that can fit in the cookie jar. If capacity is not a non-negative int, though, __init__ should instead raise a ValueError (via raise ValueError).
# __str__ should return a str with  🍪, where  is the number of cookies in the cookie jar. For instance, if there are 3 cookies in the cookie jar, then str should return "🍪🍪🍪"
# deposit should add n cookies to the cookie jar. If adding that many would exceed the cookie jar’s capacity, though, deposit should instead raise a ValueError.
# withdraw should remove n cookies from the cookie jar. Nom nom nom. If there aren’t that many cookies in the cookie jar, though, withdraw should instead raise a ValueError.
# capacity should return the cookie jar’s capacity.
# size should return the number of cookies actually in the cookie jar.
