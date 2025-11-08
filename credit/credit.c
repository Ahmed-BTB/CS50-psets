#include <cs50.h>
#include <stdio.h>
bool check_validity(long long ccn);
int find_length(long long ccn);
bool checksum(long long ccn);
void print_brand_name(long long ccn);

// we are going to prompt the user for a Credit card number and verify it if it's valid  we are
// going to give the type(Visa,American Express,Mastercard)
int main(void)
{
    long long ccn;
    do
    {
        ccn = get_long_long("Number: ");
    }
    while (ccn < 0);

    if (check_validity(ccn))
    {
        print_brand_name(ccn);
    }
    else
    {
        printf("INVALID\n");
    }
}

// declaring a function that verifies if the credit card is valid without having to querry all of
// the database to find it
bool check_validity(long long ccn)
{
    int len = find_length(ccn);
    return (len == 13 || len == 15 || len == 16) && checksum(ccn);
}

// declaring a function that finds the lengthe of the credit card number
int find_length(long long n)
{
    int len = 0;
    while (n != 0)
    {
        n /= 10;
        len++;
    }
    return len;
}

// declaring a function that runs Luhn's algorithm which determines if a credit card number is
// syntactically valid or not
bool checksum(long long ccn)
{
    int sum = 0;
    for (int i = 0; ccn != 0; i++, ccn /= 10)
    {
        int digit = ccn % 10;
        if (i % 2 == 0)
        {
            sum += ccn % 10;
        }
        else
        {
            digit = 2 * (ccn % 10);
            sum += digit / 10 + digit % 10;
        }
    }
    return sum % 10 == 0;
}

// printing the brand name
void print_brand_name(long long ccn)
{
    // finding the first two digits of the Credit Card Number
    long long start = ccn;
    while (start >= 100)
        start /= 10;

    long long start1 = ccn;
    while (start1 >= 10)
        start1 /= 10;

    int len = find_length(ccn);
    if ((start == 34 || start == 37) && len == 15)

        printf("AMEX\n");
    else if ((start >= 51 && start <= 55) && len == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((len == 13 || len == 16) && start1 == 4)
    {
        printf("VISA\n");
    }
    else
        printf("INVALID\n");
}
