#include <cs50.h>
#include <stdio.h>

int main(void)
{

    string nameGiveUser = get_string("What's your name? ");

    printf("hello, %s\n", nameGiveUser);

    return 0;
}
