#include <cs50.h>
#include <math.h>
#include <stdio.h>

int LetterCount(string text);
int WordsCount(string text);
int SentencesCount(string text);
void IndexCalculation(string text);

int main(void)
{
    // Get the text from the user
    string textGiveUser = get_string("Text: ");

    // Calls the function to calculate the index and classify the Coleman-Liau index
    IndexCalculation(textGiveUser);
}

/* FUNCTION TO CALCULATE THE NUMBER OF WORDS
 * This function takes the text and traverses it, always adding 1 to the <totalOfWords> variable,
 * which determines the number of words at the end by counting spaces that have a letter in their
 * sequence. It starts at 1 to count the first word.
 */

int WordsCount(string text)
{
    int count = 0;
    int totalOfWords = 1;

    while (text[count] != '\0')
    {
        if (text[count] == ' ' && ((text[count + 1] >= 'A' && text[count + 1] <= 'Z') ||
                                   (text[count + 1] >= 'a' && text[count + 1] <= 'z')))
        {
            totalOfWords++;
        }
        count++;
    }

    return totalOfWords;
}

/* FUNCTION TO CALCULATE THE NUMBER OF LETTERS
 * This function takes the text and traverses it, always adding 1 to the <totalOfLetters> variable,
 * which determines the number of letters at the end by checking each item in the string array and
 * verifying if it's within the lowercase or uppercase alphabet range.
 */

int LetterCount(string text)
{
    int count = 0;
    int totalOfLetters = 0;

    while (text[count] != '\0')
    {
        if ((text[count] >= 'A' && text[count] <= 'Z') ||
            (text[count] >= 'a' && text[count] <= 'z'))
        {
            totalOfLetters++;
        }
        count++;
    }

    return totalOfLetters;
}

/* FUNCTION TO CALCULATE THE NUMBER OF SENTENCES
 * This function takes the text and traverses it, always adding 1 to the <totalOfSentences>
 * variable, which determines the number of sentences at the end by traversing all the items in the
 * string array and checking for sentence indicators (!, ?, or .).
 */

int SentencesCount(string text)
{
    int count = 0;
    int totalOfSentences = 0;

    while (text[count] != '\0')
    {
        switch (text[count])
        {
            case '!':
            case '.':
            case '?':
                totalOfSentences++;
                break;
        }
        count++;
    }

    return totalOfSentences;
}

/* PROCEDURE TO CALCULATE THE COLEMAN-LIAU INDEX
 * This function takes the user's text as an argument and calls the functions 'SentencesCount',
 * 'LetterCount', and 'WordsCount', using the values received to calculate the index. Finally, it
 * prints the text's grade level.
 */

void IndexCalculation(string text)
{
    double L = (double) LetterCount(text) / WordsCount(text) * 100;
    double S = (double) SentencesCount(text) / WordsCount(text) * 100;

    double index = 0.0588 * L - 0.296 * S - 15.8;

    int roundedIndex = round(index);

    if (index >= 8.7 && index < 8.8)
    {
        printf("Grade 8\n");
    }
    else if (roundedIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (roundedIndex > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", roundedIndex);
    }
}
