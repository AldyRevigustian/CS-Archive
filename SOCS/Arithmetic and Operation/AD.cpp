#include <stdio.h>

int main() {
    int A, B, C;
    double damage;

    scanf("%d %d %d", &A, &B, &C);

    damage = 0.20 * A + 0.30 * B + 0.50 * C;

    printf("%.2lf\n", damage);

    return 0;
}
