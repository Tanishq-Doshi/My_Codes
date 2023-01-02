#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number;
    srand(time(0));
    number = rand() % 100 + 1; // Generates a random number between 1 and 100
    int i=0;
    for (int guess; guess != number; i++)
    {
        printf("What's your guess? \n");
        scanf("%d", &guess);
        if (guess > number)
        {
            printf("Lower number please.\n");
        }
        if (guess < number)
        {
            printf("Higer number please.\n");
        }
    }
    printf("You guessed the number right. The number is %d and the number of guesses you took are %d", number, i);
    return 0;
}