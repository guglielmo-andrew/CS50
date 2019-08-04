//Using the Caesar Cypher
#include <cs50.h>
#include <stdio.h>
#include <string.h>

char move (char c, int key);

int main(int argc, string argv[])
{
    //Checking validity of the input key.
    if (argc != 2)  
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    { 
        printf("Got in here. Plaintext[i] is: %c.\n", plaintext[i]);
        if (plaintext[i] > 'a' && plaintext[i] < 'Z')
        {
            ciphertext[i] = move(plaintext[i], key);
            if (plaintext[i] > 'a' && plaintext[i] < 'z' && ciphertext[i] > 'z')
            {
                ciphertext[i] -= ('z' - 'a');
            }                

            if (ciphertext[i] > 'Z')
            {
                ciphertext[i] -= ('Z' - 'A');
            }    
        }
    }
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

char move (char c, int key)
{
    return c = c + key;
}
