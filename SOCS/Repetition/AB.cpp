#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i < T + 1; i++)
  {
    int N, A, B, C, D;

    scanf("%d %d %d %d %d", &N, &A, &B, &C, &D);

    int count = 0;
    for (int i = 1; i <= N; i++)
    {
      if (i % A == 0 || i % B == 0 || i % C == 0 || i % D == 0)
      {
        count++;
      }
    }

    printf("Case #%d: %d\n", i, count);
  }

  return 0;
}