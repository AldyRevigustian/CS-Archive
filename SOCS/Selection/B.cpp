#include <stdio.h>

int main()
{
  int A;
  scanf("%d", &A);

  for (int i = 1; i < A + 1; i++)
  {
    int K, N, M;
    scanf("%d %d %d", &K, &N, &M);

    if (N + M >= K)
    {
      printf("Case #%d: %s\n", i, "yes");
    }
    else
    {
      printf("Case #%d: %s\n", i, "no");
    }
  }

  return 0;
}