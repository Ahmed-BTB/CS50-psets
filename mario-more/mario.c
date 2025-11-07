cd
#include <cs50.h>
#include <stdio.h>
int hight(void);
void print_hashes(int h);
void print_spaces(int h);
int main(void)
{
    int h = hight();
    for (int i = 0; i < h; i++)
    {
        print_spaces(h - (i + 1));
        print_hashes(i + 1);
        print_spaces(2);
        print_hashes(i + 1);
        printf("\n");
    }
}

void print_hashes(int h)
{
    for (int i = 0; i < h; i++)
    {
        printf("#");
    }
}
void print_spaces(int h)
{
    for (int i = 0; i < h; i++)
    {
        printf(" ");
    }
}

int hight(void)
{
    int n;
    do
    {
        n = get_int("give me the hight: ");
    }
    while (n > 8 || n < 1);
    return n;
}
