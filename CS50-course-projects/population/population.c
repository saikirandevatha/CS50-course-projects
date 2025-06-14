#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int x;
    int y;

    do
    {
        x = get_int("llamas start at: ");
    }
    while (x<9);

    // TODO: Prompt for end size

      do
    {
        y = get_int("llamas end at: ");
    }
    while (y<x);

    // TODO: Calculate number of years until we reach threshold

     int n=0;
    // printf("start logic");
   // printf("divisions are %d, %d", x/3, x/4);
    // n= (y-x)/((x/3)-(x/4));
    while (x<y)
    {
        x+=((x/3)-(x/4));
        n++;
    }

     printf("Years: %d\n",n);





    // TODO: Print number of years
}
