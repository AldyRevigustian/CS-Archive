#include <stdio.h>

int main()
{
  scanf("%d");
  for (int i = 0; i < 3; i++)
  {
    long long int A, B;
    scanf("%lld %lld", &A, &B);
    double persen = (double)A / 100;
    printf("%.2lf\n",  persen * B);
  }
  return 0;
}