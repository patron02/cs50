#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //define variables
    float change;
    
    //prompt the user for an answer
    do
    {
        change = get_float("How much change is owed?\n");
    }
    while (change < 0);
    
    //define coins and cents
    int cents = round(change * 100);
    int coins = 0; 
    
    //set of coins
    int denominations[] = {25, 10, 5, 1};
    int variable = sizeof(denominations) / sizeof(int);
    for (int i = 0; i < variable; i++)
    {
        coins += cents / denominations[i];
        cents %= denominations[i];
    }
    //print number of coins needed
    printf("%i\n", coins);
}
