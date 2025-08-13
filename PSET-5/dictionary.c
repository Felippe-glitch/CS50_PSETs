// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

unsigned int table_val;
unsigned int word_count;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    table_val = hash(word);
    node *cursor = table[table_val];

    while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long total = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("erro to open the dictionary");
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *alocate = malloc(sizeof(node));

        if (alocate == NULL)
        {
            return false;
        }

        strcpy(alocate->word, word);
        table_val = hash(word);
        alocate->next = table[table_val];
        table[table_val] = alocate;
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor)
        {
            node *t = cursor;
            cursor = cursor->next;
            free(t);
        }
    }
    return true;
}
