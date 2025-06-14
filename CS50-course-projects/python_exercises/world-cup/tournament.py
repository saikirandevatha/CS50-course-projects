# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():
    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    f = open(sys.argv[1])
    reader = csv.DictReader(f)
    for line in reader:
        teams.append({"team": line["team"], "rating": int(line["rating"])})

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    for _ in range(0, N):
        champion = simulate_tournament(teams)
        # print(champion)
        team = champion
        if team not in counts:
            counts[team] = 1
            # print(counts)
        else:
            counts[team] += 1
    # print(counts)

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    winners = simulate_round(teams)
    if len(winners) > 1:
        return simulate_tournament(winners)
    else:
        return winners[0]["team"]


if __name__ == "__main__":
    main()


# You might be wondering what actually happened at the 2018 and 2019 World Cups!
# For Men’s, France won, defeating Croatia in the final. Belgium defeated England for the third place position.


# For Women’s, the United States won, defeating the Netherlands in the final. England defeated Sweden for the third place position.
