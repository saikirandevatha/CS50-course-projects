#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x,i,j,k;
    int printspaces(int);
    do
    {
        x=get_int("Height: ");
    }
    while (x<1 || x>8);

//print the lines with hashes

    for (i=1; i<=x; i++)
    {
        j=1;
        k=x-i;
        printspaces(k);

        while(j<=i)
        {
            printf("#");
            j++;
        }
        printf("\n");
    }

}


//invert the pyramid

    int printspaces(k)
    {
        int l=1;
        while (l<=k)
       { printf(" ");
        l++;
       }
       return 0;
    }




