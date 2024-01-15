#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);
  int arr[N];

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &arr[i]);
  }

  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int A, B;
    scanf("%d %d", &A, &B);

    arr[A - 1] = B;

    printf("Case #%d: ", i);
    for (int j = 0; j < N; j++)
    {
      if (j != N - 1)
      {
        printf("%d ", arr[j]);
      }
      else
      {
        printf("%d", arr[j]);
      }
    }
    printf("\n");
  }

  return 0;
}