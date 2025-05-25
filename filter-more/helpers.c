#include "helpers.h"
#include <math.h>

#define RED_COLOR 0
#define GREEN_COLOR 1
#define BLUE_COLOR 2

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int grayRGB = round((image[row][column].rgbtBlue + image[row][column].rgbtGreen +
                                 image[row][column].rgbtRed) /
                                3.0);

            image[row][column].rgbtBlue = grayRGB;
            image[row][column].rgbtRed = grayRGB;
            image[row][column].rgbtGreen = grayRGB;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width / 2; column++)
        {
            temp = image[row][column];
            image[row][column] = image[row][width - column - 1];
            image[row][width - column - 1] = temp;
        }
    }
    return;
}

int getBlur(int i, int j, int heigth, int width, RGBTRIPLE image[heigth][width], int color_position)
{
    float cont = 0;
    int sum = 0;

    for (int row = i - 1; row <= (i + 1); row++)
    {
        for (int column = j - 1; column <= (j + 1); column++)
        {
            if (row < 0 || row >= heigth || column < 0 || column >= width)
            {
                continue;
            }
            if (color_position == RED_COLOR)
            {
                sum += image[row][column].rgbtRed;
            }
            else if (color_position == GREEN_COLOR)
            {
                sum += image[row][column].rgbtGreen;
            }
            else
            {
                sum += image[row][column].rgbtBlue;
            }
            cont++;
        }
    }
    return round(sum / cont);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            copy[row][column] = image[row][column];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            image[row][column].rgbtBlue = getBlur(row, column, height, width, copy, BLUE_COLOR);
            image[row][column].rgbtGreen = getBlur(row, column, height, width, copy, GREEN_COLOR);
            image[row][column].rgbtRed = getBlur(row, column, height, width, copy, RED_COLOR);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int GxRed = 0, GyRed = 0;
            int GxGreen = 0, GyGreen = 0;
            int GxBlue = 0, GyBlue = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    if (ni < 0 || ni >= height || nj < 0 || nj >= width)
                    {
                        continue;
                    }

                    int kernelRow = di + 1;
                    int kernelCol = dj + 1;

                    GxRed += copy[ni][nj].rgbtRed * Gx[kernelRow][kernelCol];
                    GyRed += copy[ni][nj].rgbtRed * Gy[kernelRow][kernelCol];

                    GxGreen += copy[ni][nj].rgbtGreen * Gx[kernelRow][kernelCol];
                    GyGreen += copy[ni][nj].rgbtGreen * Gy[kernelRow][kernelCol];

                    GxBlue += copy[ni][nj].rgbtBlue * Gx[kernelRow][kernelCol];
                    GyBlue += copy[ni][nj].rgbtBlue * Gy[kernelRow][kernelCol];
                }
            }

            int finalRed = round(sqrt(GxRed * GxRed + GyRed * GyRed));
            int finalGreen = round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen));
            int finalBlue = round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue));

            if (finalRed > 255)
            {
                finalRed = 255;
            }
            if (finalGreen > 255)
            {
                finalGreen = 255;
            }
            if (finalBlue > 255)
            {
                finalBlue = 255;
            }

            image[i][j].rgbtRed = finalRed;
            image[i][j].rgbtGreen = finalGreen;
            image[i][j].rgbtBlue = finalBlue;
        }
    }
}
