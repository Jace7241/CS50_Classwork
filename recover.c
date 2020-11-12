#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include<stdbool.h>
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening raw file occured");
        return 1;
    }

    typedef uint8_t BYTE;
    BYTE buffer[BLOCK_SIZE];

    //Now we have a file
    size_t bytes_read;
    bool is_first_jpeg = false;
    FILE *current_file;
    char current_filename[100];
    int current_filenumber = 0;
    bool found_jpeg = false;

    //open memory card
    while (true)
    {


        //Repeat till end of card
        //Read 512 bytes into a buffer
        bytes_read = fread(buffer, sizeof(BYTE), BLOCK_SIZE, file);
        if (bytes_read == 0)
        {
            break; //end of file
        }

        //if start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer [3] & 0xf0) == 0xe0)
        {
            found_jpeg = true;
            //If first JPEG
            // mark first JPEG
            if (!is_first_jpeg)
            {
                is_first_jpeg = true;
            }


            else
            {

                //close file/open new file
                fclose(current_file);

            }
            sprintf(current_filename, "%03i.jpg", current_filenumber);
            current_file = fopen(current_filename, "w");
            fwrite(buffer, sizeof(BYTE), bytes_read, current_file);
            current_filenumber++;//filenum = 1;

        }
        else
        {
            if (found_jpeg)
            {
                fwrite(buffer, sizeof(BYTE), bytes_read, current_file);

            }
            //if found JPEG , keep writing
            //keep writing
        }

    }
    fclose(file);
    fclose(current_file);
    return 0;
}
