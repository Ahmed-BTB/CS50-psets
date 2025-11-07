#include <cs50.h>
#include <stdio.h>

// We are going to create a program that prompts the user for their name and says hallo to them
int main(void)
{
    string answer = get_string("what's your name: ");
    printf("hello, %s\n", answer);
}
