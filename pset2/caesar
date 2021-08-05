#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool check_valid_key(string s);

//points to the first and last command line
int main(int argc, string argv[])
{
    if (argc != 2) //if command line doesn't == 2
    {
        printf("Usage ./caeser key\n");
        return (1);
    }
    int key = atoi(argv[1]);
    if (key < 0)
    {
        printf("key must be positive\n");
        return (1);
    }
    //asks the user for text
    string plaintext = get_string("plaintext: ");
    //prints out ciphertext
    printf("ciphertext: ");
    //cipher 
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char m = 'A';
            if (islower(c))
            {
                m = 'a';
            }
            printf("%c", (c - m + key) % 26 + m);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return (0);
}

