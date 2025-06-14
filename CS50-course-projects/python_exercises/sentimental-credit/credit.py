# TODO

# All  American Express numbers start with American34 or 37;
#     most MasterCard numbers start with 51, 52, 53, 54, or 55
#     and all Visa numbers start with 4

#  American Express uses 15-digit numbers,
# MasterCard uses 16-digit numbers,
# and Visa uses 13- and 16-digit numbers.

# Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
# Add the sum to the sum of the digits that weren’t multiplied by 2.
# If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
import re

pattern = r"\d{13,16}"
while True:
    try:
        cc = input("Number: ")
        if re.fullmatch(pattern, cc):
            break
        else:
            print("INVALID")
            break
    except ValueError:
        None

sum1 = 0
sum2 = 0
counter = 0
cc1=cc
cc = int(cc)

while cc > 0:
    sum2 += cc % 10
    j = 2 * ((cc % 100) // 10)
    while j > 0:
        sum1 += j % 10
        j //= 10
    if cc > 9:
        counter += 2
    else:
        counter += 1
    cc = cc // 100
#     print(cc)
# print(counter)

if (sum1 + sum2) % 10 == 0 and counter > 12 and counter < 17:
    if re.match(r"^34|^37", cc1) and counter == 15:
        print("AMEX")
    elif re.match(r"^(51|52|53|54|55)", cc1) and counter == 16:
        print("MASTERCARD")
    elif re.match(r"^4", cc1) and (counter == 13 or counter == 16):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")


# def luhn_checksum(card_number):
#     sum_odd, sum_even = 0, 0
#     reversed_digits = [int(d) for d in card_number[::-1]]

#     for i, digit in enumerate(reversed_digits):
#         if i % 2 == 0:
#             sum_odd += digit
#         else:
#             doubled = digit * 2
#             sum_even += doubled if doubled < 10 else doubled - 9

#     return (sum_odd + sum_even) % 10 == 0
