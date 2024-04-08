#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int input, number;

    number = rand() % 10 + 1;

    do
    {
        printf("\nEnter a number: ");
        scanf("%d", &input);

        if (input < number)
        {
            printf("\n!! :(Too low!");
        }
        else if (input > number)
        {
            printf("\n!! :(Too hight!");
        }
        else
        {
            printf(";) you found it!");
        }

    } while (input != number);

    return 0;
}
