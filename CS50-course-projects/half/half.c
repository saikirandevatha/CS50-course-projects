// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip_percent);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip_percent)
{

   // printf("entered bill, tax percent and tip percent are %f, %f and %d\n", bill, tax, tip_percent);
    float net_tax = bill * (tax/100);
   // printf("net_tax is %f\n", net_tax);
    float bill_posttax = bill + net_tax;
   // printf("bill_posttax is %f\n", bill_posttax);

    float net_tip = bill_posttax * ((float)tip_percent / 100);
    //    printf("net_tip is %f\n", net_tip);

    float total_bill= bill + net_tax + net_tip;
       // printf("total_bill is %f\n", total_bill);

    float halfof = total_bill/2;
     //   printf("halfof is %f\n", halfof);

    return halfof;
}
