#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// We are going to create a program that encrypts a text with shifting letters by a certain number
// of letters
int main(int argc, string argv[])
{
    // at the command line we prompt the user for the key which is the value that we are going to
    // shift letters with that value has to be numeric and the user must only type one numeric value
    // once
    if (argc != 2)
    {
        printf("Usage ./caeser key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage ./caeser key\n");
            return 1;
        }
    }
    // now we prompt the user for the text and encrypt it
    string plaintext = get_string("Plainext: ");
    printf("ciphertext: ");
    int k = atoi(argv[1]);
    for (int i = 0; i < strlen(plaintext); i++)
    {

        if (isupper(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 65 + k) % 26 + 65);
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 97 + k) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
