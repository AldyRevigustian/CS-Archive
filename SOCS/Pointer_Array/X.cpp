#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int N, M;
    scanf("%d %d", &N, &M);

    long long int max_weight = 0;
    long long int weight = 0;

    for (int j = 0; j < N; j++)
    {
      long long int max_in_row = 0;
      for (int k = 0; k < M; k++)
      {
        scanf("%lld", &weight);
        if (weight > max_in_row)
        {
          max_in_row = weight;
        }
      }
      max_weight += max_in_row;
    }

    printf("Case #%d: %lld\n", i, max_weight);
  }

  return 0;
}
