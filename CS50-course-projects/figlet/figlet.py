import sys
from sys import argv
from pyfiglet import Figlet
figlet = Figlet()
font_list=figlet.getFonts()
print(font_list)
for font in font_list:
    print(font)

if len(argv) == 3 and (argv[1]=="-f" or argv[1] == "--font") and argv[2] in font_list:
    text= input("Input: ")
    figlet.setFont(font=argv[2])
    print(figlet.renderText(text))

else:
    print("Usage: figlet.py -f/--font rectangles")
    sys.exit(1)











# Expects zero or two command-line arguments:
# Zero if the user would like to output text in a random font.
# Two if the user would like to output text in a specific font, in which case the first of the two should be -f or --font, and the second of the two should be the name of the font.
# Prompts the user for a str of text.
# Outputs that text in the desired font.
# If the user provides two command-line arguments and the first is
#       not -f or --font or the second is not the name of a font, the program should exit via sys.exit with an error message.
