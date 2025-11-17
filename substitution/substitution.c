#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype: checks if the key is valid (26 unique letters)
bool check_char(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        // Check if the user provided exactly one argument (the key)
        printf("Usage: ./substitution KEY \n");
        return 1;
    }

    if (!check_char(argv[1]))
    {
        // Validate the key: must contain 26 unique alphabetic characters
        printf("Key must contain 26 unique characters.\n");
        return 1;
    }
    // Prompt user for plaintext to encrypt
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    int length = strlen(plaintext); // Length of the input plaintext
    string key = argv[1];           // The substitution key

    // Create an array to store the ciphertext; +1 for the null terminator
    char ciphertext[length + 1];
    ciphertext[length] = '\0'; // Null-terminate the string

    // Loop through each character in the plaintext
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // If the character is lowercase
        if (islower(plaintext[i]))
        {
            int index = plaintext[i] - 'a'; // Find its position in the alphabet (0-25)
            ciphertext[i] = key[index];     // Substitute using the key

            // Ensure the ciphertext letter is lowercase
            if (isupper(ciphertext[i]))
            {
                ciphertext[i] += 32; // Convert uppercase from key to lowercase
            }
        }
        else if (isupper(plaintext[i]))
        {
            int index = plaintext[i] - 'A';
            ciphertext[i] = key[index];
            if (islower(ciphertext[i]))
            {
                ciphertext[i] -= 32;
            }
        }

        // If the character is non-alphabetic (numbers, punctuation, space)
        else
        {
            ciphertext[i] = plaintext[i]; // Leave it unchanged
        }
    }
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

// Function to check if the key is valid
bool check_char(string key)
{
    int length = strlen(key);
    if (length != 26)
    {
        return false;
    }
    for (int i = 0; i < length; i++)
    {
        // Convert to uppercase
        key[i] = toupper(key[i]);
    }
    for (int i = 0; i < length; i++)
    {
        // check if it's a letter
        if (!isalpha(key[i]))
        {
            return false;
        }
        // Check for duplicates
        for (int j = i + 1; j < length; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
    return true;
}
