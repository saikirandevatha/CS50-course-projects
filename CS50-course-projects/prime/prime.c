#include <cs50.h>
#include <stdio.h>

bool prime(int i);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int i)
{
    // TODO
    for (int j=2; j<i; j++)
    {
        //printf("entered: %d",i/j);
        if((i%j)==0)

       // printf("remainder of %d/%d is %d",i,j,i/j);
        return false;
    }
    return true;
}
