#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int total;
    float change;
    do
    {
        change = get_float ("Change - ");
        
        total = (change * 100);
    }
    while (change <0.01);
    
    int quarter = total / 25;
    int dime = (total / 25)/10;
    int nickel = ((total /25)/10)/5;
    int penny = (((total /25)/10)/5)/1;
    int amount = quarter + dime + nickel + penny;
    printf("%0i\n", amount);
}