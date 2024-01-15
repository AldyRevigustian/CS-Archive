#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; i++)
  {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int j = 0; j < N; j++)
    {
      scanf("%d", &arr[j]);
    }
    int banyak = 0;
    int max = 0;

    for (int j = 0; j < N; j++)
    {
      if (arr[j] > max)
      {
        max = arr[j];
      }
    }

    for (int j = 0; j < N; j++)
    {
      if (arr[j] == max)
      {
        banyak++;
      }
    }

    printf("Case #%d: %d\n", i + 1, banyak);
  }

  return 0;
}