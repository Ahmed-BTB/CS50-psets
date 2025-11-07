#include <cs50.h>
#include <stdio.h>
int leftover(void);
int main(void)
{
    int n = leftover();
    int count = 0;
    count = count + n / 25;
    n = n % 25;
    count = count + n / 10;
    n = n % 10;
    count = count + n / 5;
    n = n % 5;
    count += n;
    printf("%i\n", count);
}

int leftover(void)
{
    int n;
    do
    {
        n = get_int("Leftover: ");
    }
    while (n < 1);
    return n;
}
