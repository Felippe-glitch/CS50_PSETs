#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
} candidate;

candidate candidates[MAX];

int candidate_count;

bool vote(string name);

void print_winner(void);

/*  ==> MAIN FUNCTION
 *
 *  This is the main function where the program starts execution. It first checks if
 *  there are enough command-line arguments. Then, it initializes the candidates and
 *  sets their initial vote counts to 0. It collects votes from the voters and finally
 *  displays the winner(s) of the election.
 */

int main(int argc, string argv[])
{

    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    print_winner();
}

/*  ==> PREDICATE TO VALIDATE THE VOTE
 *
 *   This function checks if a vote is valid by searching for a candidate with the
 *   given name. If found, it increments the candidate's vote count and returns true.
 *   Otherwise, it returns false to indicate an invalid vote.
 */

bool vote(string name)
{

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

/*  ==> FUNCTION TO PRINT THE WINNER(S)
 *
 *   This function identifies the candidates with the maximum number of votes
 *   and prints their names. If there is a tie, it prints all the names of the tied
 *   candidates. The function uses a flag to manage printing multiple winners on
 *   separate lines.
 */

void print_winner(void)
{

    int max_votes = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    bool first = true;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            if (!first)
            {
                printf("\n");
            }
            printf("%s", candidates[i].name);
            first = false;
        }
    }
    printf("\n");
}
