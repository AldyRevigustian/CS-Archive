#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; ++t)
  {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; ++i)
    {
      scanf("%d", &A[i]);
    }

    int P, Q;
    scanf("%d %d", &P, &Q);

    if (A[P - 1] > A[Q - 1])
    {
      printf("Case #%d : Bibi\n", t);
    }
    else if (A[P - 1] < A[Q - 1])
    {
      printf("Case #%d : Lili\n", t);
    }
    else
    {
      printf("Case #%d : Draw\n", t);
    }
  }

  return 0;
}
