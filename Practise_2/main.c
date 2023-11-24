#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playSlotMachine() {
    srand(time(NULL));
    int coins = 100;
    printf("Welcome to the Slot Machine Game!\n");
    printf("Game Rules:\n");
    printf("- You have a certain number of coins.\n");
    printf("- You place a bet and enter the length of the sequence of digits.\n");
    printf("- If the sequence contains at least one digit 7, you get your bet back.\n");
    printf("- If all digits in the sequence are the same, you win extra.\n");
    printf("- If at least one-third of the digits are the same, you get your bet back.\n");
    printf("Wins:\n");
    printf("- If at least one 7 is present: return your bet.\n");
    printf("- If all digits are the same: double your bet.\n");
    printf("- If at least one-third of the digits are the same: return your bet.\n");

    int length;
    printf("Enter the length of the sequence: ");
    scanf("%d", &length);

    while (coins > 0) {
        int bet, win = 0;
        printf("You have %d coins\n", coins);
        printf("Enter your bet (0 to quit): ");
        scanf("%d", &bet);

        if (bet == 0)
            break;
        if (bet > coins) {
            printf("You cannot bet more than you have!\n");
            continue;
        }

        int *sequence = malloc(length * sizeof(int));
        if (sequence == NULL) {
            printf("Memory allocation error!\n");
            return;
        }

        printf("Sequence: ");
        for (int i = 0; i < length; i++) {
            sequence[i] = rand() % 10;
            printf("%d ", sequence[i]);
            if (sequence[i] == 7)
                win = bet;
        }
        printf("\n");

        int *frequency = calloc(10, sizeof(int));
        if (frequency == NULL) {
            free(sequence);
            printf("Memory allocation error!\n");
            return;
        }

        for (int i = 0; i < length; i++) {
            frequency[sequence[i]]++;
        }

        for (int i = 0; i < 10; i++) {
            if (frequency[i] == length) {
                win = (i == 7) ? bet * 3 : bet * 2;
                printf("All digits are the same! Win: %d\n", win);
                break;
            }
        }

        for (int i = 0; i < 10; i++) {
            if (frequency[i] >= (length + 2) / 3) {
                if (win == 0) {
                    win = bet;
                    printf("At least one-third of the digits are the same! Win: %d\n", win);
                }
                break;
            }
        }

        coins = coins - bet + win;

        if (win) {
            printf("Congratulations! You won %d coins\n", win);
        } else {
            printf("Sorry! You lost your bet!\n");
        }

        free(sequence);
        free(frequency);

        if (coins == 0) {
            printf("You've run out of coins!\n");
        }
    }
    printf("Game over!\n");
    printf("You have %d coins remaining\n", coins);
}

int main() {
    playSlotMachine();
    return 0;
}
