#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++)
  {
    long long int N, X, Y;
    scanf("%lld %lld %lld", &N, &X, &Y);
    long long int jojonanci[21];
    jojonanci[0] = X;
    jojonanci[1] = Y;
    // jojonanci[0] = 2;
    // jojonanci[1] = 3;

    if (N > 1)
    {
      for (int i = 2; i <= N; i++)
      {
        jojonanci[i] = jojonanci[i - 1] - jojonanci[i - 2];
        // jojonanci[2] = jojonanci[1] - jojonanci[2];
      }
    }

    printf("Case #%d: %lld\n", t, jojonanci[N]);
  }
  return 0;
}
