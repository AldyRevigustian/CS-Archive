#include <stdio.h>

int main() {
    char nama[100];
    scanf("%100[^\n]", nama);
    printf("Congrats \"%s\" for joining the CS department at BINUS.\n", nama);

    return 0;
}