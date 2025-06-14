import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    statelists = {}
    prevcases = {}
    # cases_type = type(row['cases'])
    # print(f"The data type of 'cases' is: {cases_type}")
    for row in reader:
        state = row["state"]
        cases = int(row["cases"])
        if state not in statelists:
            statelists[state] = {"currindex": 0, "caseslist": [0] * 14}
            prevcases[state] = 0
        currindex = statelists[state]["currindex"]
        caseslist = statelists[state]["caseslist"]
        if currindex > 13:
            caseslist.pop(0)
            caseslist.append(cases - prevcases[state])
        else:
            caseslist[currindex] = cases - prevcases[state]
        currindex += 1
        statelists[state]["currindex"] = currindex
        prevcases[state] = cases

    # print(f"prevcases are {prevcases}")

    return statelists


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        # print(f"{state} is {new_cases[state]}")
        lastweekavg = sum(new_cases[state]["caseslist"][7:]) / 7
        prevweekavg = sum(new_cases[state]["caseslist"][:7]) / 7
        diffinpercent = (lastweekavg - prevweekavg) / prevweekavg * 100
        if diffinpercent > 0:
            print(
                f"{state} had a 7-day average of {lastweekavg:.2f} and an increase of {diffinpercent:.2f}%"
            )
        else:
            print(
                f"{state} had a 7-day average of {lastweekavg:.2f} and an decrease of {diffinpercent:.2f}%"
            )


main()


# seven-day-average/ $ python seven-day-average.py
# Choose one or more states to view average COVID cases.
# Press enter when done.

# State: Massachusetts
# State: New York
# State:

# Seven-Day Averages
# Massachusetts had a 7-day average of 1646 and an increase of 46%.
# New York had a 7-day average of 7502 and a decrease of 1%.
