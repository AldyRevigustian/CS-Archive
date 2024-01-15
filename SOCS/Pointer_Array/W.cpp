#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++)
  {
    int N;
    scanf("%d", &N);
    int arr[N];

    for (int j = 0; j < N; j++)
    {
      scanf("%d", &arr[j]);
    }

    int temp[N] = {0};

    for (int j = 0; j < N - 1; j++)
    {
      for (int k = j + 1; k < N; k++)
      {
        for (int l = 0; l < N; l++)
        {
          if (arr[j] + arr[k] == arr[l])
          {
            temp[l]++;
          }
        }
      }
    }

    int isCool = 0;

    for (int j = 0; j < N; j++)
    {
      if (temp[j] != 0)
      {
        isCool++;
      }
    }

    printf("Case #%d: %d\n", i, isCool);
  }

  return 0;
}
