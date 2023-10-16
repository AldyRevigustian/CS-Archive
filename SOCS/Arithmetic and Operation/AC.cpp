#include <stdio.h>
#include <math.h>

int main()
{
  long long int A;
  scanf("%lld", &A);
  long long int pangkat = pow(2, A);

  printf("%lld\n", pangkat - 1);
  return 0;
}
