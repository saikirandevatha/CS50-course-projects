import csv
import sys


def main():
    # TODO: Check for command-line usage

    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    db_names = []
    db = open(sys.argv[1])
    reader = csv.DictReader(db)
    for row in reader:
        db_names.append(row)
    db.close()
    # print(db_names)

    # TODO: Read DNA sequence file into a variable

    seq_file = open(sys.argv[2])
    seq = seq_file.read()
    seq_file.close()
    # print(seq)
    result_dict = {}

    # TODO: Find longest match of each STR in DNA sequence
    for i in db_names:
        # print(i)
        for key in i:
            # print("key: " , key)
            if key != "name":
                longest_run = longest_match(seq, key)
                # print(key, longest_run)
                result_dict[key] = longest_run
                # print("result_dict is " , result_dict)
        break

    # TODO: Check database for matching profiles
    name = ""

    for i in db_names:
        keyindex = 1
        for key in i:
            if key != "name":
                if i[key] != str(result_dict[key]):
                    break
                keyindex += 1
            if key != "name" and keyindex == len(i):
                name = i["name"]
    if name == "":
        print("No match")
    else:
        print(name)

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()




# def main():
#     # Check for command-line usage
#     if len(sys.argv) != 3:
#         sys.exit("Usage: python dna.py data.csv sequence.txt")

#     # Read database file into a variable
#     with open(sys.argv[1], 'r') as file:
#         reader = csv.DictReader(file)
#         db_data = list(reader)

#     # Read DNA sequence file into a variable
#     with open(sys.argv[2], 'r') as file:
#         sequence = file.read().strip()

#     # Find longest match of each STR in DNA sequence
#     str_counts = {str_name: longest_match(sequence, str_name) for str_name in db_data[0] if str_name != 'name'}

#     # Check database for matching profiles
#     for person in db_data:
#         if all(person[str_name] == str(str_counts[str_name]) for str_name in str_counts):
#             print(person['name'])
#             return

#     print("No match")

# def longest_match(sequence, subsequence):
