#include <stdio.h>

int main()
{
  int M, N;
  scanf("%d %d", &M, &N);

  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    // for (int j = 1; j < N; j++)
    {
      for (int k = 0; k < N - j - 1; k++)
      // for (int k = 0; k < 3 - 1 - 1; k++)
      {
        printf(" ");
      }
      for (int k = 0; k < j + 1; k++)
      // for (int k = 0; k < 1 + 1; k++)
      {
        printf("*");
      }
      printf("\n");
    }
  }

  return 0;
}