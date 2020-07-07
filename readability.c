#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>


int main(void)
{
    //asks for input
    string s = get_string("Text - ");
    // sets beginning values
    int lettercount = 0;
    int wordcount = 1;
    int sentancecount = 0;


    //word count for the final
    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            lettercount ++;
        }
        else if (s[i] == ' ')
        {
            wordcount ++;
        }
        else if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentancecount ++;
        }
    }


//Math of the readability
    float level = 0.0588 * (100 * (float) lettercount / (float) wordcount) - 0.296 * (100 * (float) sentancecount /
                  (float)wordcount) - 15.8;
    //prints final answer
    if (level < 16 && level > 0)
    {
        printf("Grade %i\n", (int) round(level));
    }
    else if (level >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (level <= 0)
    {
        printf("Before Grade 1\n");
    }
}

