#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);

  int arr[N][N];
  int temp[N + 1] = {0};

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int currentIndex = arr[i][j];
      if (arr[i][j] != 0)
      {
        temp[arr[i][j]]++;
      }
    }
  }

  int incomplete = 0;

  for (int i = 0; i < N + 1; i++)
  {
    // printf("Index %d : %d\n", i, temp[i]);
    if (i != 0 && temp[i] < N)
    {
      incomplete++;
    }
  }

  printf("%d\n", incomplete);

  return 0;
}