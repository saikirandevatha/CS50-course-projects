#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{

    int length = strlen(input);
    int rem = 0, number = 0;
    if (length > 0)
    {
        number = input[length - 1] - '0';
        input[length - 1] = '\0';
        rem = convert(input);
    }
    return (rem * 10) + number;
}