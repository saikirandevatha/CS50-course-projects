# TODO


def main():
    text = input("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = (100 * letters) / words
    S = (100 * sentences) / words

    index = int(round(0.0588 * L - 0.296 * S - 15.8))

    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print("Grade ", index)


def count_letters(text):
    letters = 0
    for c in text:
        if c.isalpha():
            letters += 1
    return letters


def count_words(text):
    words = 1
    for c in text:
        if c == " ":
            words += 1
    return words


def count_sentences(text):
    sentences = 0
    for c in text:
        if c == "." or c == "?" or c == "!":
            sentences += 1
    return sentences


main()



# def main():
#     text = input("Text: ")
#     letters = sum(c.isalpha() for c in text)
#     words = text.count(' ') + 1
#     sentences = sum(c in ".?!" for c in text)

#     L = (100 * letters) / words
#     S = (100 * sentences) / words

#     index = round(0.0588 * L - 0.296 * S - 15.8)

#     if index < 1:
#         print("Before Grade 1")
#     elif index > 16:
#         print("Grade 16+")
#     else:
#         print(f"Grade {index}")

# main()
