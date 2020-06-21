#include <stdio.h>
#include <cs50.h>
//uses round command with the math library
#include <math.h>

int main(void)
{
    float change;
    int  total;
    do
    {
        //asks user to insert number
        change = get_float("Amount owed - ");
        //rounds number and multiplies into whole number
        total = round(change * 100);
//does not allow negatives or 0
    } 
    while (change <= 0);

    int amount = 0;
    //if the rounded total is above a certain number subtract by that number until it gets to be a smaller specific number
    while (total >= 25)
    {
        amount++;
        total = total - 25;
    }


    while (total >= 10)
    {
        amount++;
        total = total - 10;
    }

    while (total >= 5)
    {
        amount++;
        total = total - 5;
    }

    while (total >= 1)
    {
        amount++;
        total = total - 1;
    }

    printf("%i\n", amount);
}