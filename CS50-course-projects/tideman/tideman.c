#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX] = {0};

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool checkcycle(int i, int j, int pairindex);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    printf("preferences are \n");

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%d\t", preferences[i][j]);
        }
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    int j = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            j++;
        }
    }
    if (j == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int x = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] - preferences[j][i] > 0)
            {
                pair_count++;
                pairs[x].winner = i;
                pairs[x].loser = j;
                x++;
            }
        }
    }
    printf("pair count is %d \npairs are as follows \n", pair_count);
    for (int i = 0; i < pair_count; i++)
        printf("%d %d \n", pairs[i].winner, pairs[i].loser);

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    printf("ENTERED SORTING\n");

    for (int i = 0; i < pair_count; i++)
    {
        int temp[2] = {0, 0};
        for (int j = 0; j < pair_count - 1; j++)
        {

            if (preferences[pairs[j].winner][pairs[j].loser] < preferences[pairs[j + 1].winner][pairs[j + 1].loser])
            {
                temp[0] = pairs[j].winner;
                temp[1] = pairs[j].loser;
                pairs[j].winner = pairs[j + 1].winner;
                pairs[j].loser = pairs[j + 1].loser;
                pairs[j + 1].winner = temp[0];
                pairs[j + 1].loser = temp[1];
            }
        }
        if (temp[0] == 0 && temp[1] == 0)
        {
            printf("sorted  pairs are as follows \n");
            for (int x = 0; x < pair_count; x++)
                printf("%d\t%d \n", pairs[x].winner, pairs[x].loser);
            return;
        }
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!checkcycle(pairs[i].winner, pairs[i].loser, i))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
            // printf("locked pair %d:  winner is candiate %s and loser is candidate %s", i, candidates[pairs[i].winner],
            // candidates[pairs[i].loser]);
        }
    }

    printf("locked pairs are as follows \n");
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%d\t", locked[i][j]);
        }
        printf("\n");
    }
    return;
}

bool checkcycle(int i, int j, int pairindex)
{
    for (int p = 0; p < pairindex; p++)
    {
        if (j == pairs[p].winner && pairs[p].loser == i)
            return 1;
        else if (j == pairs[p].winner && pairs[p].loser != i)
        {
            if (checkcycle(i, pairs[p].loser, pairindex))
                return 1;
        }
    }
    return 0;
}

// Print the winner of the election
void print_winner(void)
{
    for (int j = 0; j < candidate_count; j++)
    {
        int x = 0;
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[i][j] == true)
            {
                x++;
                break;
            }
        }
        if (x == 0)
            printf("%s\n", candidates[j]);
    }
    return;
}