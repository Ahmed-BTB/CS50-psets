#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int count_sentences(string text);
int count_words(string text);
int count_letters(string text);
int main(void)
{
    // prompt the user for text
    string text = get_string("Text:");

    // count the number of letters and sentences  in 100 words
    float W = count_words(text);
    float L = (count_letters(text) / W) * 100;
    float S = (count_sentences(text) / W) * 100;
    // compute the coleman-liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // print the grade level
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
        printf("Grade %.0f\n", index);
    }
}

int count_letters(string text)
{
    // returns the number of letters in the text
    int L = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (('A' <= text[i] && text[i] <= 'Z') || ('a' <= text[i] && text[i] <= 'z'))
        {
            L++;
        }
    }
    return L;
}

int count_words(string text)
{
    // Return the number of words in text
    int W = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            W++;
        }
    }
    return W;
}
int count_sentences(string text)
{
    // Return the number of sentences in text
    int S = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            S++;
        }
    }
    return S;
}
