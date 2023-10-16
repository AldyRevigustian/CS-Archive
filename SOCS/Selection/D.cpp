#include <stdio.h>

int main()
{
  int A;
  scanf("%d", &A);

  for (int i = 1; i < A + 1; i++)
  {
    long long int K, N;
    scanf("%lld %lld", &K, &N);

    if (K * N % 2 == 0)
    {
      printf("Case #%d: %s\n", i, "Party time!");
    }
    else
    {
      printf("Case #%d: %s\n", i, "Need more frogs");
    }
  }

  return 0;
}