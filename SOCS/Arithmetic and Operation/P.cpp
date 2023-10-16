#include <stdio.h>

int main()
{
    for (int i = 0; i < 4; i++)
    {
        int N, P;
        scanf("%d %d", &N, &P);
        double harga = (double)P / (1 - ((double)N / 100));
        printf("$%.2f\n", harga);
    }
    return 0;
}