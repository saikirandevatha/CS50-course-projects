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

// no of words in dictionary;
int dictsize = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 66653;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int h = hash(word);
    node *curr = table[h];
    // printf("%p\t%p \n", curr, table[h]);
    while (curr != NULL)
    {
        if (strcasecmp(curr->word, word) == 0)
            return true;
        curr = curr->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';
    // int sum =0;
    // for(int i=0; word[i] != '\0' ; i++)
    // sum+= tolower(word[i])-'A';
    // return sum%N;
    unsigned long hash = 77773; // Or some other prime number seed
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + tolower(c); // hash * 33 + c
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("File could not be opened\n");
        return false;
    }
    char word[46] = {0};

    // initilize all table array pointers to NULL
    for (int i = 0; i < N; i++)
        table[i] = NULL;
    while (fscanf(dict, "%s", word) == 1)
    {
        // printf("%s\n",word);
        int h = hash(word);
        node *new = malloc(sizeof(node));
        // printf("new pointer is %p\n", new);

        if (table[h] == NULL)
            new->next = NULL;
        else
            new->next = table[h];
        strcpy(new->word, word);
        table[h] = new;
        dictsize++;
        // free(new);
    }
    fclose(dict);
    // printf ("pointers after loading dict are \n");
    //  for (int i =0 ; i < N ; i++)
    //  {
    //      //printf("printing table pointers\n");
    //      //printf("%p\n",table[i]);
    //      //printf ("table[%d] is %p\t",i,table[i]);
    //      if (table[i]!= NULL)
    //      {
    //          //printf("table[i] is %p\t",table[i]);
    //          while(table[i]->next != NULL)
    //          {
    //              //printf ("%p\t",table[i]->next);
    //              table[i] = table[i]->next;
    //          }
    //          //printf ("\n");
    //      }
    //  }

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    return dictsize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *curr = table[i];
            table[i] = curr->next;
            free(curr);
            // if(curr->next != NULL)
            // {
            //     table[i] = curr->next;
            //     free(curr);
            // }
            // else
            // {
            //     table[i] = NULL;
            //     free(curr);
            // }
        }
    }
    // for (int i =0 ; i < N ; i++)
    // {
    //     printf("%p\n",table[i]);
    // }
    return true;
}
