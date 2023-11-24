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

    for (int k = 0; k < N; k++)
    {
      if (M / H[k] > count)
      {
        count = M / H[k];
      }
    }

    printf("Case #%d: %d\n", i, count);
  }

  return 0;
}
