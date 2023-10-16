#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i < T + 1; i++)
  {
    int N;
    scanf("%d", &N);

    long long int A[N];
    for (int i = 0; i < N; i++)
    {
      scanf("%lld", &A[i]);
    }

    int P, Q;
    scanf("%d %d", &P, &Q);

    if (P > N || Q > N || P == Q)
    {
      return 0;
    }
    
    if (A[P - 1] > A[Q - 1])
    {
      printf("Case #%d : %s\n", i, "Bibi");
    }
    else if (A[P - 1] < A[Q - 1])
    {
      printf("Case #%d : %s\n", i, "Lili");
    }
    else if (A[P - 1] == A[Q - 1])
    {
      printf("Case #%d : %s\n", i, "Draw");
    }
    else
    {
      return 0;
    }
  }

  return 0;
}