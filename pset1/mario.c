#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //set height out of range then ask for valid height: betwen 1 and 8
    int height = 0;
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }
    
    for (int i = 1; i < (height + 1); i++)
    {
        for (int j = (height - i); j > 0; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        //print two spaces
        printf("  ");
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
