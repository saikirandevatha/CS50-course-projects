#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    long cc =get_long("Number: ");
    long cc1=cc;
       int counter=0;
   int sum1=0;
   int sum2=0;
    while(cc>0)
    {
        sum1+=cc%10;
        int j=(cc%100)/10;
        j*=2;
        do
        {
        sum2+=j%10;
        j/=10;
        } while (j>0);
        if (cc>9)
        counter+=2;
        else
        counter+=1;
     cc=cc/100;
    }
        if(((sum1+sum2)%10==0) && counter>12 && counter <17)
        {
            switch(counter)
            {
                case 15:
                        switch(cc1/(long)pow(10,counter-2))
                          {
                        case 34:
                        case 37:
                        printf("AMEX\n");
                        exit(0);
                        default:
                        printf("INVALID\n");
                        exit(0);
                          }
                           printf("INVALID\n");
                        exit(0);
                case 13:
                     if ((cc1/(long)pow(10,counter-1))==4)
                     {
                        printf("VISA\n");
                        exit(0);
                     }
                     printf("INVALID\n");
                      exit(0);

                case 16:
                        if ((cc1/(long)pow(10,counter-1))==4)
                           {
                            printf("VISA\n");
                            exit(0);
                           }

                         else
                        {
                             switch(cc1/(long)pow(10,counter-2))
                                {
                                case 51:
                                case 52:
                                case 53:
                                case 54:
                                case 55:
                                printf("MASTERCARD\n");
                                exit(0);
                                default:
                                printf("INVALID\n");
                                exit(0);
                              }

                        }
                                default:
                                printf("INVALID\n");
                                exit(0);
            }
        }
        else
        printf("INVALID\n");
}