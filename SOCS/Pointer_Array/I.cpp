#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int N;
    scanf("%d", &N);
    long long int arr[N];

    for (int j = 0; j < N; j++)
    {
      scanf("%lld", &arr[j]);
    }

    printf("Case #%d: ", i);
    for (int j = N - 1; j >= 0; j--)
    {
      if (j != 0)
      {
        printf("%lld ", arr[j]);
      }
      else
      {
        printf("%lld", arr[j]);
      }
    }
    printf("\n");
  }

  return 0;
}