#include <stdio.h>

int main() {
    int T, Ut, Ua;
    double nilai_akhir;

    scanf("%d %d %d", &T, &Ut, &Ua);

    nilai_akhir = 0.20 * T + 0.30 * Ut + 0.50 * Ua;

    printf("%.2lf\n", nilai_akhir);

    return 0;
}
