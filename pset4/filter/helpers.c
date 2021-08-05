#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtRed + pixel.rgbtBlue + pixel.rgbtGreen) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = average;
        }
    }
    return;
}

//cap function
int cap(int value)
{
    return value > 255 ? 255 : value; 
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int originalRed = pixel.rgbtRed;
            int originalGreen = pixel.rgbtGreen;
            int originalBlue = pixel.rgbtBlue;
            image[i][j].rgbtRed = cap(round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue));
            image[i][j].rgbtGreen = cap(round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue));
            image[i][j].rgbtBlue = cap(round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue));
        }
    }
    return;
}

void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }
}

bool valid_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    return i >= 0 && i < height && j >= 0 && j < width;
}

RGBTRIPLE blur_pixels(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int redValue, blueValue, greenValue; 
    redValue = blueValue = greenValue = 0;
    int numofValidPixels = 0;
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)    
        {
            int new_i = i + di;
            int new_j = j + dj;
            if (valid_pixel(new_i, new_j, height, width, image))
            {
                numofValidPixels++;
                redValue += image[new_i][new_j].rgbtRed;
                greenValue += image[new_i][new_j].rgbtGreen;
                blueValue += image[new_i][new_j].rgbtBlue;
            }
            
        }
    }
    RGBTRIPLE blurred_pixel;
    blurred_pixel.rgbtRed = round((float) redValue / numofValidPixels);
    blurred_pixel.rgbtGreen = round((float) greenValue / numofValidPixels);
    blurred_pixel.rgbtBlue = round((float) blueValue / numofValidPixels);
    return blurred_pixel;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)   
        {
            new_image[i][j] = blur_pixels(i, j, height, width, image);    
        }
    }
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) 
        {
            image[i][j] = new_image[i][j];
        }
}
