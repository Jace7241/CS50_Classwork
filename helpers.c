#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE pixelA = image[i][j];
            int average = round((pixelA.rgbtRed + pixelA.rgbtGreen + pixelA.rgbtBlue)/3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE pixelB = image[i][j];

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
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
