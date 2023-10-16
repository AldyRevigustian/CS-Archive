#include <stdio.h>
#include <math.h>

int main() {
    double X;
    double Y;

    scanf("%lf %lf", &X, &Y);

    Y = Y / 100;

    double jumlahUang = X * pow(1 + Y, 3);
    printf("%.2lf\n", jumlahUang);
    return 0;
}
