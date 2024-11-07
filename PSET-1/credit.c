#include <cs50.h>
#include <stdio.h>

bool IsValid(long cardNumberForValidation);
void PrintCardFlag(long cardNumber);
int CountDigits(long cardNumber);
int GetFirstTwoDigits(long cardNumber);

/* MAIN FUNCTION
 * ===> The main function asks the user for the card number and first checks if the number
 * entered has more than 13 digits. If not, "INVALID" is printed. If it does, the second check
 * is performed by calling the 'IsValid' function to verify if the number follows the patterns for
 * credit card numbers. If the predicate returns true, the 'PrintCardFlag' procedure is called
 * to further validate the number and print the card brand or "INVALID".
 */

int main(void)
{
    long cardNumber = get_long("Number: ");

    if (cardNumber < 100000000000) // 12 digits or less
    {
        printf("INVALID\n");
    }
    else if (IsValid(cardNumber)) // Checks if the number is valid
    {
        PrintCardFlag(cardNumber); // Identifies the card brand
    }
    else
    {
        printf("INVALID\n");
    }
}

/* PREDICATE TO VALIDATE THE CARD NUMBER / LUHN ALGORITHM
 * ===> This predicate is an implementation of the Luhn algorithm to validate if the given
 * number follows the standard for credit card numbers. The process starts by analyzing the digits
 * of the number from right to left. For every second digit (in even positions), the number is
 * doubled. If the result of the multiplication is greater than 9, the two digits of the resulting
 * number are added. The other digits (in odd positions) are simply added. In the end, if the total
 * sum of all digits (doubled and non-doubled) is divisible by 10, the number is considered valid
 * and the function returns true. Otherwise, the number is invalid and the function returns false.
 */

bool IsValid(long cardNumberForValidation)
{
    int sumDoubledDigits = 0;
    int sumOtherDigits = 0;
    int doubledDigit = 0;
    int digitCount = 0;

    while (cardNumberForValidation > 0)
    {
        digitCount++;

        if (digitCount % 2 == 0) // If the digit is in an even position
        {
            doubledDigit = (cardNumberForValidation % 10) * 2;
            sumDoubledDigits +=
                (doubledDigit % 10) +
                (doubledDigit / 10); // Adds the two digits if the value is 10 or greater
        }
        else // If the digit is in an odd position
        {
            sumOtherDigits += cardNumberForValidation % 10;
        }

        cardNumberForValidation /= 10; // Removes the last digit
    }

    // If the sum of the digits is divisible by 10, the number is valid
    return (sumDoubledDigits + sumOtherDigits) % 10 == 0;
}

/* PROCEDURE TO RETURN THE CARD BRAND
 * ===> This function aims to return the card brand or the invalidity of the number. It receives
 * the card number and calls two functions: 'GetFirstTwoDigits' to get the first two digits of the
 * card, and 'CountDigits' to determine how many digits the card has. Finally, based on the
 * parameters of the problem, it checks if the obtained numbers match any known card brand.
 */

void PrintCardFlag(long cardNumber)
{
    // Get the first two digits of the card number
    int firstTwoDigits = GetFirstTwoDigits(cardNumber);

    // Get the total number of digits in the card number
    int quantDigits = CountDigits(cardNumber);

    // Check if the card is an American Express (AMEX)
    switch (firstTwoDigits)
    {
        case 34: // American Express starts with 34
        case 37: // or 37
            // American Express cards must have 15 digits
            if (quantDigits == 15)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n"); // Invalid if not 15 digits
            }
            break;

        // Check if the card is a MasterCard
        case 51: // MasterCard starts with 51-55
        case 52:
        case 53:
        case 54:
        case 55:
            // MasterCard cards must have 16 digits
            if (quantDigits == 16)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n"); // Invalid if not 16 digits
            }
            break;

        // Check if the card is a Visa card
        default:
            // For Visa, check if the first digit is 4
            firstTwoDigits /= 10; // Get the first digit by dividing by 10
            // Visa cards can have 13 or 16 digits
            if (firstTwoDigits == 4 && (quantDigits == 13 || quantDigits == 16))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n"); // Invalid if not 13 or 16 digits, or first digit isn't 4
            }
    }
}

/* FUNCTION THAT RETURNS THE NUMBER OF DIGITS OF A CARD
 * ===> This function uses the card number as a condition in the while loop, and while the
 * card number is greater than zero, it continues executing. With each iteration, the variable
 * 'numberOfDigits' is incremented by 1, thus obtaining the number of digits in the card number.
 */

int CountDigits(long cardNumber)
{
    int numberOfDigits = 0;

    while (cardNumber > 0)
    {
        numberOfDigits++;
        cardNumber /= 10;
    }

    return numberOfDigits;
}

/* FUNCTION THAT RETURNS THE FIRST TWO DIGITS OF A CARD
 * ===> This function receives the card number provided by the user and performs an integer division
 * until the number is less than or equal to 100. Thus, when the while loop ends, the variable
 * 'cardNumber' will hold the first two digits of the card.
 */

int GetFirstTwoDigits(long cardNumber)
{
    while (cardNumber >= 100)
    {
        cardNumber /= 10;
    }

    return cardNumber;
}
