#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixelA = image[i][j];
            int average = round((pixelA.rgbtRed + pixelA.rgbtGreen + pixelA.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixelB = image[i][j];
// convert images to pixel form
            int sepiaRed = round(.393 * pixelB.rgbtRed + .769 * pixelB.rgbtGreen + .189 * pixelB.rgbtBlue);
            int sepiaGreen = round(.349 * pixelB.rgbtRed + .686 * pixelB.rgbtGreen + .168 * pixelB.rgbtBlue);
            int sepiaBlue = round(.272 * pixelB.rgbtRed + .534 * pixelB.rgbtGreen + .131 * pixelB.rgbtBlue);

            image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        int Pos = 0;
        for (int j = width - 1; j >= 0; j--, Pos++)
        {
            temp[i][Pos] = image[i][j];
        }
    }
//copy to final
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Blur image
//slight blur
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int Coun = 0;
            int rowCoords[] = { row - 1, row, row + 1 };
            int colCoords[] = { col - 1, col, col + 1 };
            float totalR = 0, totalG = 0, totalB = 0;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int curRow = rowCoords[r];
                    int curCol = colCoords[c];
//change pixel each tome for precision
                    if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width)
                    {
                        RGBTRIPLE pixelC = image[curRow][curCol];

                        totalR += pixelC.rgbtRed;
                        totalG += pixelC.rgbtGreen;
                        totalB += pixelC.rgbtBlue;
                        Coun++;
                    }
                }
            }
            temp[row][col].rgbtRed = round(totalR / Coun);
            temp[row][col].rgbtGreen = round(totalG / Coun);
            temp[row][col].rgbtBlue = round(totalB / Coun);
        }
    }
// copy fianl image direct
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;

}
