#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int N;
    scanf("%d", &N);
    int arr[N][N];

    for (int j = 0; j < N; j++)
    {
      for (int k = 0; k < N; k++)
      {
        scanf("%d", &arr[j][k]);
      }
    }

    int temp[N] = {0};

    for (int j = 0; j < N; j++)
    {
      for (int k = 0; k < N; k++)
      {
        temp[k] = arr[j][k] + temp[k];
      }
    }

    printf("Case #%d: ", i);
    for (int j = 0; j < N; j++)
    {
      if (j != N - 1)
      {
        printf("%d ", temp[j]);
      }
      else
      {
        printf("%d", temp[j]);
      }
    }

    printf("\n");
  }

  return 0;
}
