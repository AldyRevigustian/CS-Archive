#include <stdio.h>

int main()
{
  int N, Q;
  scanf("%d", &N);
  int tayangan[N];

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &tayangan[i]);
  }

  scanf("%d", &Q);

  for (int i = 1; i <= Q; i++)
  {
    int A, B;
    scanf("%d %d", &A, &B);

    int total_tayangan = 0;

    for (int j = A - 1; j < B; j++)
    {
      total_tayangan += tayangan[j];
    }

    printf("Case #%d: %d\n", i, total_tayangan);
  }

  return 0;
}