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


def get_number_input(prompt, error_message):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print(error_message)

# Setup the jar
while True:
    max_capacity = get_number_input("Enter maximum capacity of the jar: ", "Invalid capacity entered, enter again.")
    try:
        jar = Jar(max_capacity)
        break
    except ValueError as e:
        print(e)

# Main interaction loop
while True:
    question = input("Would you like to deposit or withdraw? Enter D or W: ").lower()
    if question == 'd':
        deposit_amount = get_number_input("How many cookies would you like to deposit? ", "Invalid number, try again.")
        try:
            jar.deposit(deposit_amount)
        except ValueError as e:
            print(e)
            continue  # Go back to the start of the loop
    elif question == 'w':
        withdraw_amount = get_number_input("How many cookies would you like to withdraw? ", "Invalid number, try again.")
        try:
            jar.withdraw(withdraw_amount)
        except ValueError as e:
            print(e)
            continue  # Go back to the start of the loop
    else:
        print("Invalid entry, try again.")
        continue

    print(jar)
    if jar.size < 1:
        print("The jar is empty.")
        break

print("Zero cookies left.")
