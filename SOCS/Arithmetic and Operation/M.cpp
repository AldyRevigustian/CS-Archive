#include <stdio.h>

int main() {
    long long int X, Y;
    double percentage;

    scanf("%lld %lld", &X, &Y);

    percentage = ((double)X / Y) * 100;
    printf("%.2lf%%\n", percentage);

    return 0;
}