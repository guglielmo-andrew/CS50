#include <cs50.h>
#include <stdio.h>

int card_ints[16];

int main(void)
{
    //get the card number and test for proper length
    long card = get_long("Number: ");
    if (card < 999999999999 || card > 9999999999999999)
    {
        printf("INVALID\n");
        return 1;
    }
    //create a temp array of ints to hold the card number; will be backwards
    int k = 0;
    int ar_temp[16];    
    while(card)//To get the number of digits
    {
        int r = card % 10;
        card = card / 10;
        ar_temp[k] = r;
        k++;
    }
    //initialize the array of ints
    int ar[16];
    //reverse the array to be in order
    for (int i = 0; i < k; i++)
    {
        ar[i] = ar_temp[k-1-i]; 
    }
    
    int left_overs = 0;
    int to_double[9];
    int x = 0;
    for (int i = 0; i < k; i++)
    {
        if (i % 2 == 0)
        {
            to_double[x] = ar[i] * 2;   
            x++;
        }
        else
        {
            left_overs += ar[i];
        }
    }
    //validate card number with Luhn's Algorithm
    int doubled = 0;
    int temp_ar_prods[2];
    for (int i = 0; i < x; i++)
    {
        if (to_double[i] < 10)
        {
            doubled += to_double[i];    
        }
        else //for instances where the doubled digit is now more than digit
        {
            temp_ar_prods[0] = to_double[i] % 10;
            temp_ar_prods[1] = (to_double[i] / 10) % 10;
            doubled = doubled + temp_ar_prods[0] + temp_ar_prods[1];
        }
    }
    if ((left_overs + doubled) % 10 == 0)
    {
        if (ar[0] == 3)
        {
            printf("AMEX\n");
        }
        else if (ar[0] == 5)
        {
            printf("MASTERCARD\n");
        }
        else if (ar[0] == 4)
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
        //printf("Doubled: %i; Left_overs: %i, x: %i\n", doubled, left_overs, x);
        //for (int i = 0; i < x; i++)
        //{
        //    printf(" %d", to_double[i]);
        //}
        //printf("\n");
    }
}
