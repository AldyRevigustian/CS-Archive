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
    int cmp[N];

    for (int j = 0; j < N; j++)
    {
      scanf("%d", &arr[j]);
    }

    for (int j = 0; j < N; j++)
    {
      scanf("%d", &cmp[j]);
    }

    int tmp = 0;
    for (int j = 0; j < N; j++)
    {
      if (arr[j] < cmp[j])
      {
        tmp++;
      }
    }
    printf("Case #%d: %d\n", i, tmp);
  }

  return 0;
}