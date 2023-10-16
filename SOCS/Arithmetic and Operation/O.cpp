#include <stdio.h>

int main()
{
  for (int i = 0; i < 4; i++)
  {
    long long int A, B;
    scanf("%lld %lld", &A, &B);
    printf("%lld\n", A * B);
  }

  return 0;
}