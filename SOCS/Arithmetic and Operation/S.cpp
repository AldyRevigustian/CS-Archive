#include <stdio.h>
#include <math.h>

int main() {
    double L, B, H;
    scanf("%lf %lf %lf", &L, &B, &H);

    double luas_alas = B * H / 2.0;
    double keliling_tinggi = (B * 3.0) * L;
    double luas_total = (2.0 * luas_alas) + keliling_tinggi;

    printf("%.3lf\n", luas_total);
    return 0;
}
