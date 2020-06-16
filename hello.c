#include <stdio.h>
#include <cs50.h>


int main(void)
{
    //asks name and stores name into a variable
    string name = get_string("What's your name?\n");
    //uses variable to say hello here
    printf("Hello, %s\n", name);
}