#include <cs50.h>
#include <stdio.h>
int height(void);
void print_row(int a, int b);
int main(void)
{
    int h = height();
    for (int i = 0; i < h; i++)
    {
        print_row(h, i+1);
    }
}

// print the rows
void print_row(int a, int b)
{
    for (int j = 0; j < a - b; j++)
    {
        printf(" ");
    }
    for (int j = 0; j < b; j++)
    {
        printf("#");
    }
    printf("\n");
}

// prompt the user for the hight of the pyramid
int height(void)
{
    int n;
    do
    {
        n = get_int("hight");
    }
    while (n < 1 || n > 8);
    return n;
}
