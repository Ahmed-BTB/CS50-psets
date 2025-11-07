#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int a = get_int("a: ");
    int b = get_int("b: ");
    printf("%.3f\n", (float)a/b);


}
