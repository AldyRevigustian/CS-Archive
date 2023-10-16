#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int N, M;
    scanf("%d %d", &N, &M);

    int H[N];
    for (int j = 0; j < N; j++)
    {
      scanf("%d", &H[j]);
    }

    int count = 0;
    int temp = 0;

    for (int k = 0; k < N; k++)
    {
      int count2 = 0;

      for (int l = 0; l < M; l++)
      {
        temp = temp + H[k];
        if (temp <= M)
        {
          printf("Perulangan si %d : %d\n", H[k], temp);
          count2++;
        }
      }

      // printf("Count %d: %d\n", k, count2);
    }

    // printf("Case #%d: %d\n", i, count);
  }

  return 0;
}