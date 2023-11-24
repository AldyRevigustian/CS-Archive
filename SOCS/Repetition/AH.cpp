#include <stdio.h>

int main()
{
  int T;

  scanf("%d", &T);

  for (int j = 1; j <= T; j++)
  {
    long long int angka;
    scanf("%lld", &angka);
    long long int i = angka;
    long long int banyakDigit = 0;

    while (i > 0)
    {
      i = (i - (i % 10)) / 10;
      banyakDigit++;
    }

    printf("Case #%d: %lld\n", j, banyakDigit);
  }
}