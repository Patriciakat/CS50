// LUHN'S ALGORITHM

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_nr = get_long("Enter credit card number: \n");
    long shorter_nr = card_nr / 10;
    long for_first = card_nr;
    int every_first;
    int every_second;
    int mult = 0;
    int a;
    int add_first = 0;
    int card_length = 0;
    bool is_valid;

    // calculate checksum

    while (shorter_nr > 0)
    {
        every_second = shorter_nr % 10;

        if (every_second >= 5)
        {
            a = (every_second * 2);
            mult += (a%10) + (a/10);
        }
        else
        {
            mult += (every_second * 2);
        }

        shorter_nr = shorter_nr / 100;

        card_length++;
    }

    while (for_first > 0)
    {
        every_first = for_first % 10;
        add_first += every_first;

        for_first = for_first / 100;

        card_length++;
    }

    if ((mult + add_first) % 10 == 0)
    {
        is_valid = true;
    }
    else
    {
        is_valid = false;
    }

    // check for card length and starting digits

    long first_two = card_nr;

    while (first_two > 99)
    {
        first_two = first_two / 10;
    }

    // print AMEX, MASTERCARD, VISA or INVALID

    if (is_valid)
    {
        if ((first_two == 34 || first_two == 37) && card_length == 15 )
        {
            printf("AMEX\n");
        }

        if ((first_two >= 51 && first_two <= 55) && card_length == 16)
        {
            printf("MASTERCARD\n");
        }

        if ((card_length == 13 || card_length == 16) && (first_two >= 40 && first_two <= 49))
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}