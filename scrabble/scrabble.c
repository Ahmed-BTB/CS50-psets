// This program in C determines the winner of a short scrabble-like game
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
//points assigned to each letter of the alphabet
int const POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int main(void)
{
    // prompt the user two times for a word
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // compute the score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    // indicate the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{

    int score = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        //if the letter in the word is majuscule we substitute the A ASCII number from the letter ASCII number wen end up with the index of the letter in POINTS Array same for the minuscule with substituting the 'a' character
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}
