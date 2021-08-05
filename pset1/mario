#include <stdio.h>
#include <cs50.h>

int main(void)
{ 
    int height, row, column, space;
    do
    {
    //ask user for the height
   height = get_int("What height will your stairs be?\n");
    }while (height < 1 || height > 8);

    //make the columns dependent on the rows
    for (row = 0; row < height; row++)
    {
        //add spaces before
        for (space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        //format the stairs
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}
   
