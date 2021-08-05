#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h> 
#include <math.h>

int main(void)
{
    //ask the reader for input
    string s = get_string("Text: ");
    //define the variables
    int letters, words, sentences; 
    letters = words = sentences = 0;
    //find all integers 
    for (int i = 0; i < strlen(s); i++)
    {
        char j = s[i];
        //find number of letters
        if (isalpha(j))
        {
            letters++;
        }
        //find number of words
        if (isspace(j))
        {
            words++;
        }
        //find number of sentences
        if (j == '.' || j == '?' || j == '!')
        {
            sentences++;
        }
    }
    words++;
    
    //define equation
    float L = (letters * 100) / words;
    float S = (sentences * 100) / words;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    //print out grade
    if (index < 1)
    
    {
        printf("Before Grade 1\n");
    }
    
    else if (index >= 16)
    
    {
        printf("Grade 16+\n");
    }
    
    else
    
    {
        printf("Grade %i\n", index);
    }
    
}
