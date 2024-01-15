#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  int arr[T];

  for (int i = 0; i < T; i++)
  {
    scanf("%d", &arr[i]);
  }

  int U;
  scanf("%d", &U);

  for (int i = 0; i < U; i++)
  {
    int K = 0, L = 0, total = 0;

    scanf("%d %d", &K, &L);

    for (int j = K - 1; j <= L - 1; j++)
    {
      total += arr[j];
    }

    printf("Case #%d: %d\n", i + 1, total);
  }

  return 0;
}