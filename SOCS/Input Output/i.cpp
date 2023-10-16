#include <stdio.h>

int main() {
    char nama[100];
    scanf("%100[^\n]", nama);
    printf("Hello %s!\n", nama);

    return 0;
}