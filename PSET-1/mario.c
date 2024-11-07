#include <cs50.h>
#include <stdio.h>

void TrianglePrint(int sizeController);

/* MAIN FUNCTION
 * ===> The main function asks for user input and validates it (ensuring it is greater than one),
 * then calls the TrianglePrint procedure, which prints the two pyramids.
 */

int main(void)
{

    int triangleSize = 0;

    do
    {
        // Asks the user for the triangle size
        triangleSize = get_int("Size: ");

        if (triangleSize >= 1)
        {

            // Calls the 'TrianglePrint' procedure to print the triangles
            TrianglePrint(triangleSize);

            break;
        }
    }
    while (triangleSize < 1);
}

/* PROCEDURE TO CREATE THE TRIANGLES
 * ===> The 'TrianglePrint' function prints two triangles made of `#` characters on each line, with
 * a space between them. The number of lines and the width of the triangles are determined by the
 * 'sizeController' parameter. On each line, the function first prints an increasing number of
 * spaces, then prints the triangles (one on the left and the other on the right), with a fixed
 * space between them. This process repeats, decreasing the number of '#' characters and the
 * remaining lines until all layers are printed. The value of 'sizeController' defines the overall
 * size of the generated pattern.
 */
void TrianglePrint(int sizeController)
{

    int sizeProvidedProcessing = sizeController;

    // Loop to create the layers of the triangles
    while (0 < sizeProvidedProcessing)
    {

        // Generates the spaces between the #
        for (int blankCounter = 0; blankCounter < sizeProvidedProcessing - 1; blankCounter++)
        {
            printf(" ");
        }

        // Generates the left-side #
        for (int counterLeftSideTriangle = 0;
             counterLeftSideTriangle < sizeController - (sizeProvidedProcessing - 1);
             counterLeftSideTriangle++)
        {
            printf("#");
        }

        // Separation between the triangles
        printf("  ");

        // Generates the right-side #
        for (int counterRightSideTriangle = 0;
             counterRightSideTriangle < sizeController - (sizeProvidedProcessing - 1);
             counterRightSideTriangle++)
        {
            printf("#");
        }

        printf("\n");

        sizeProvidedProcessing -= 1;
    }
}
