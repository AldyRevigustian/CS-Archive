#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);
  int arr[2][N];

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < N; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  int tmp[N];
  for (int i = 0; i < N; i++)
  {
    tmp[arr[0][i]] = arr[1][i];
  }

  for (int i = 0; i < N; i++)
  {
    if (i != N - 1)
    {
      printf("%d ", tmp[i]);
    }
    else
    {
      printf("%d", tmp[i]);
    }
  }
  printf("\n");

  return 0;
}