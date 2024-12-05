#include <cs50.h>
#include <stdio.h>

int PointsPlayer(string wordPlayer);

int main(void)
{
    // Get the words from both players
    string wordPlayerOne = get_string("Player 1: ");
    string wordPlayerTwo = get_string("Player 2: ");

    // Calculate the scores for both players
    int pointsOne = PointsPlayer(wordPlayerOne);
    int pointsTwo = PointsPlayer(wordPlayerTwo);

    // Compare the scores and print the result
    if (pointsOne > pointsTwo)
    {
        printf("Player 1 wins!\n");
    }
    else if (pointsOne < pointsTwo)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

/* Function to calculate the score of a word.
 * The function iterates over each letter and adds points based on the letter.
 */
int PointsPlayer(string wordPlayer)
{
    int points = 0;

    // Iterate over each character in the word until the end of the string
    for (int i = 0; wordPlayer[i] != '\0'; i++)
    {
        // Check the current letter and add corresponding points
        switch (wordPlayer[i])
        {
            case 'A':
            case 'a':
            case 'I':
            case 'i':
            case 'E':
            case 'e':
            case 'L':
            case 'l':
            case 'N':
            case 'n':
            case 'O':
            case 'o':
            case 'S':
            case 's':
            case 'T':
            case 't':
            case 'U':
            case 'u':
            case 'R':
            case 'r':
                points += 1;
                break;
            case 'D':
            case 'd':
            case 'G':
            case 'g':
                points += 2;
                break;
            case 'B':
            case 'b':
            case 'C':
            case 'c':
            case 'M':
            case 'm':
            case 'P':
            case 'p':
                points += 3;
                break;
            case 'F':
            case 'f':
            case 'H':
            case 'h':
            case 'V':
            case 'v':
            case 'W':
            case 'w':
            case 'Y':
            case 'y':
                points += 4;
                break;
            case 'K':
            case 'k':
                points += 5;
                break;
            case 'J':
            case 'j':
            case 'X':
            case 'x':
                points += 8;
                break;
            case 'Q':
            case 'q':
            case 'Z':
            case 'z':
                points += 10;
                break;
            default:
                break;
        }
    }

    return points;
}
