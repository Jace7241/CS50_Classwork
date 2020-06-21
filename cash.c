#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    int  total;
    do
    {
        change = get_float ("Amount owed - ");
        total = round(change*100);

    }while (change <= 0);

    int amount = 0;
    while(total >= 25) {
        amount++;
        total = total - 25;
    }


    while(total >= 10) {
        amount++;
        total = total - 10;
    }

    while(total >= 5) {
        amount++;
        total = total - 5;
    }

    while(total >= 1) {
        amount++;
        total = total - 1;
    }

    printf("%i\n", amount);
}