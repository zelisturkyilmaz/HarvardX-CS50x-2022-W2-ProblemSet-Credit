#include <cs50.h>
#include <stdio.h>
#include <math.h>

long find_digit(long x, int y)
{
    return (x % (long)pow(10, y)) / (long)pow(10, y - 1);
}

int main(void)
{
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    } while (card_number < 0);

    int length = 0;
    long digitnumber = card_number;
    while (digitnumber > 0)
    {
        digitnumber = digitnumber / 10;
        length++;
    }
    // printf("%i\n", length);
    long sum_eo = 0;
    long sum = 0;
    long product_digit;
    for (int i = 1; i <= length; i++)
    {
        // printf("%li ", find_digit(card_number, length+1-i));
        if (i % 2 != 0)
        {
            sum = sum + find_digit(card_number, i);
        }
        else
        {
            product_digit = 2 * find_digit(card_number, i);
            sum_eo = sum_eo + ((product_digit % 10) + (product_digit / 10));
        }
    }
    // printf("\n");
    // printf("sum is: %li\n", sum);
    // printf("sum_eo is: %li\n", sum_eo);
    long sum_total = sum + sum_eo;
    bool testm = (find_digit(card_number, length) == 5 && (find_digit(card_number, length - 1) == 1 || find_digit(card_number, length - 1) == 2 || find_digit(card_number, length - 1) == 3 || find_digit(card_number, length - 1) == 4 || find_digit(card_number, length - 1) == 5));
    bool testa = find_digit(card_number, length) == 3 && (find_digit(card_number, length - 1) == 4 || find_digit(card_number, length - 1) == 7);
    if (sum_total % 10 == 0 && length == 15 && testa)
    {
        printf("AMEX\n");
    }
    else if (sum_total % 10 == 0 && length == 16 && testm)
    {
        printf("MASTERCARD\n");
    }
    else if (sum_total % 10 == 0 && (length == 16 || length == 13) && find_digit(card_number, length) == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// American Express uses 15-digit numbers. Start with 34 or 37
// MasterCard uses 16-digit numbers. Start with 51,52,53,54,55
// Visa uses 13-and16-digit numbers. Start with 4

// Luhn's algorithm
// Multiply every other digit by 2, starting with the number’s second-to-last digit,
// and then add those products’ digits together.
// Add the sum to the sum of the digits that weren’t multiplied by 2.
// If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is
// congruent to 0), the number is valid!

// Ask user for card number
// Check if card number input is long
// We cannot use arrays yet so i need to find length
// from length i can find the integers in every decimal power
// find the (*2) values of every other second to last digit
// add together this values with other digits
// find the remainder from %10
// If the card is valid
// Check the digit length and the digits that its start with to decide company