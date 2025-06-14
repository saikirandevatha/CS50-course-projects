#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE *sparepixel = malloc(sizeof(RGBTRIPLE));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            *sparepixel = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = *sparepixel;
        }
    }

    free(sparepixel);

    // RGBTRIPLE *sparecolumn=malloc(height * sizeof(RGBTRIPLE));

    // for (int j=0; j < width/2 ; j++)
    // {

    //     memcpy(sparecolumn , image[j] , height * sizeof(RGBTRIPLE));
    //     memcpy(image[j] , image[width-1-j] , height * sizeof(RGBTRIPLE));
    //     memcpy(image[width-1-j] , sparecolumn, height * sizeof(RGBTRIPLE));
    // }
    // free(sparecolumn);

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempimage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int g = 0, b = 0, r = 0;
            int n = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int new_i = i + di;
                    int new_j = j + dj;
                    if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
                    {
                        g += image[new_i][new_j].rgbtGreen;
                        b += image[new_i][new_j].rgbtBlue;
                        r += image[new_i][new_j].rgbtRed;

                        n++;
                    }
                }
            }
            tempimage[i][j].rgbtGreen = round((float) g / n);
            tempimage[i][j].rgbtBlue = round((float) b / n);
            tempimage[i][j].rgbtRed = round((float) r / n);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempimage[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE tempimage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int gx = 0, bx = 0, rx = 0, gy = 0, by = 0, ry = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int new_i = i + di;
                    int new_j = j + dj;
                    int m = 1 + di;
                    int n = 1 + dj;
                    int Gxkernel[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
                    int Gykernel[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
                    if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
                    {

                        gx += image[new_i][new_j].rgbtGreen * Gxkernel[m][n];
                        bx += image[new_i][new_j].rgbtBlue * Gxkernel[m][n];
                        rx += image[new_i][new_j].rgbtRed * Gxkernel[m][n];

                        gy += image[new_i][new_j].rgbtGreen * Gykernel[m][n];
                        by += image[new_i][new_j].rgbtBlue * Gykernel[m][n];
                        ry += image[new_i][new_j].rgbtRed * Gykernel[m][n];
                    }
                }
            }
            tempimage[i][j].rgbtGreen = (BYTE) (fmin(255, round(sqrt(pow(gx, 2) + pow(gy, 2)))));
            tempimage[i][j].rgbtBlue = (BYTE) (fmin(255, round(sqrt(pow(bx, 2) + pow(by, 2)))));
            tempimage[i][j].rgbtRed = (BYTE) (fmin(255, round(sqrt(pow(rx, 2) + pow(ry, 2)))));
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempimage[i][j];
        }
    }

    return;
}
