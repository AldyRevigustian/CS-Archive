#include <stdio.h>

int main() {
    char S[100];
    scanf("%100[^\n]", S);

    printf("Happy Birthday to %s.\n", S);

    return 0;
}