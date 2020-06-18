#include<stdio.h>
#include<cs50.h>
int main (void)
{
   int number = 0;
   int n;
   //asks for positive number less than 23
    do 
    {
        n = get_int("positive number - ");                                   

    }
    while(n < 0 || n > 23); 
//prints spaces as an upsidedown triangle
    for(int integer = n; integer > 0; integer--) //controlls rows              
    {
        for(int i = 0; i < integer - 1; i++)                  
        {
            printf(" ");

        }
        //prints the right angled triangle
        printf("#");
        number++;
        controlls how many hashes in a row
        for (int a = 0; a < number-1; a++)
        {
            printf("#");
        }
        printf("\n");
    }
}