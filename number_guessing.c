#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5
#define MIN_NUMBER 1
#define MAX_NUMBER 100

int getGuess(int min, int max) {
    int guess;
    printf("\nEnter a number between %d and %d: ", min, max);
    scanf("%d", &guess);
    return guess;
}

void printFeedback(int guess, int number) {
    if (guess < number) {
        printf("Your guess is too low!\n");
    } else if (guess > number) {
        printf("Your guess is too high!\n");
    } else {
        printf("Congratulations! You found it!\n");
    }
}

int main(void) {
    srand(time(NULL));
    int number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
    int guess, attempts = 0;

    printf("Welcome to the Number Guessing Game!\n");

    do {
        guess = getGuess(MIN_NUMBER, MAX_NUMBER);
        printFeedback(guess, number);
        attempts++;
    } while (guess != number && attempts < MAX_GUESSES);

    if (attempts >= MAX_GUESSES) {
        printf("Sorry, you've run out of attempts. The correct number was %d.\n", number);
    }

    char playAgain;
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &playAgain);

    if (playAgain == 'y' || playAgain == 'Y') {
        main(); // Restart the game
    }

    return 0;
}
