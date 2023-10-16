#include <stdio.h>
#include <string.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i < T + 1; i++)
  {
    int N, M;
    scanf("%d %d", &N, &M);

    printf("Case #%d:\n", i);
    for (int j = 0; j < N; j++)
    {
      for (int k = 0; k < M; k++)
      {
        if (j == 0 || j == N - 1)
        {
          printf("#");
        }
        else if (k == 0 || k == M - 1)
        {
          printf("#");
        }
        else
        {
          printf(" ");
        }
      }
      printf("\n");
    }
  }

  return 0;
}