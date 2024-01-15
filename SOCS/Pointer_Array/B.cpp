#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int N;
    scanf("%d", &N);
    int arr[2][N];

    for (int j = 0; j < 2; j++)
    {
      for (int k = 0; k < N; k++)
      {
        scanf("%d", &arr[j][k]);
      }
    }

    int temp[N];
    for (int k = 0; k < N; k++)
    {
      temp[k] = arr[0][k] - arr[1][k];
    }

    printf("Case #%d: ", i);
    for (int k = 0; k < N; k++)
    {
      if (k != N - 1)
      {
        printf("%d ", temp[k]);
      }
      else
      {
        printf("%d", temp[k]);
      }
    }
    printf("\n");
  }

  return 0;
}