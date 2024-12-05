#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintCipher(string word, int interval);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    char *endptr;
    long distance = strtol(argv[1], &endptr, 10);

    if (*endptr != '\0' || distance <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string nome = get_string("Placeholder: ");
    PrintCipher(nome, (int) distance);

    return 0;
}

void PrintCipher(string word, int interval)
{
    int length = strlen(word);

    printf("ciphertext: ");

    for (int i = 0; i < length; i++)
    {
        char letter = word[i];

        if (isalpha(letter))
        {
            char base = isupper(letter) ? 'A' : 'a';
            putchar((letter - base + interval) % 26 + base);
        }
        else
        {
            putchar(letter);
        }
    }

    printf("\n");
}
