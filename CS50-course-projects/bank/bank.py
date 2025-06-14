greeting = input("Greetings!\n")
while greeting == "":  # Checks if the input is an empty string
    print("You must enter at least one character.")
    greeting = input("Please enter a greeting:\n ")
if "hello" in greeting.strip().lower() :
    print ("$0")
elif greeting[0].lower() == "h" :
    print ("$20")
else :
    print ("$100")
