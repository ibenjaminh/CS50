#include <stdio.h>
#include <stdlib.h>

int main() {
    int winner = 21;
    int programmer = 43;
    int player;
    printf("Player please pick a number: ");
    scanf("%d", &player);

    int diff1 = abs(winner - programmer);
    int diff2 = abs(winner - player);

    if (diff1 < diff2) {
        printf("Dealer has %d. Dealer wins\n", programmer);
    } else if (diff2 < diff1) {
        printf("PLayer has %d. Player wins\n", player);
    } else {
        printf("Player and Dealer are equally distant\n");
    }

    return 0;
}
