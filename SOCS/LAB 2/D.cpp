#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    double reamur[N], fahrenheit[N], kelvin[N];

    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A); 

        reamur[i] = (4.0 / 5.0) * (double)A;
        fahrenheit[i] = (9.0 / 5.0) * (double)A + 32.0;
        kelvin[i] = (double)A + 273.00;
    }

    for (int i = 0; i < N; i++) {
        printf("%.2lf %.2lf %.2lf\n", reamur[i], fahrenheit[i], kelvin[i]);
    }

    return 0;
}
