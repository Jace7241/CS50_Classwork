#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("nope\n");
        return 1;
    }
    if(argc == 2 && isdigit (*argv[1]))
    {

        int k = atoi(argv[1]);


        if(k<0)
        {
            printf("nope\n");
        }


        string sentance = get_string("Plaintext: ");


        for(int i = 0, n = strlen(sentance); i<n; i++)
        {
            if(sentance[i] >= 'a' && sentance[i] <= 'z')
            {
                printf("%c", (((sentance[i] + k) - 97) % 26) + 97);
            }
            else if(sentance[i] >= 'A' && sentance[i] <='Z')
            {
                printf("cyphertext: ");
                printf("%c", (((sentance[i] +k) - 65) %26) + 65);
            }
            else
            {
                printf("cyphertext: ");
                printf("%c", sentance[i]);
            }
        }
        printf("");
        return 0;
    }
}