#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    long long A, N;
    long long MOD = 1000000007;

    scanf("%lld %lld", &A, &N);
    // scanf("%lld %lld", 2, 5);

    long long result = 1;
    for(int j = 0; N > j;)
    // 5 > 0
    {
      if (N % 2 == 1)
      // if (5 % 2 == 1)
      {
        result = (result * A) % MOD;
        // result = (1 * 2) % MOD;
        // result = 2;

        // result = (2 * 16) % MOD;
        // result = 32;
      }
      A = (A * A) % MOD;
      // A = (2 * 2) % MOD;
      // A = 4;

      // A = (4 * 4) % MOD;
      // A = 16;

      N = N / 2;
      // N = 5 / 2;
      // N = 2;

      // N = 2 / 2;
      // N = 1;
    }

    printf("Case #%d: %lld\n", i, result);
  }

  return 0;
}
