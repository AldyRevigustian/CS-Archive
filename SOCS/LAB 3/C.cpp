#include <stdio.h>

int main()
{
  int A;
  scanf("%d", &A);

  for (int i = 1; i < A + 1; i++)
  {
    int K, N;
    scanf("%d %d", &K, &N);

    if (K == N)
    {
      return 0;
    }
    
    if (K > N)
    {
      printf("Case #%d: %s\n", i, "Go-Jo");
    }
    else
    {
      printf("Case #%d: %s\n", i, "Bi-Pay");
    }
  }

  return 0;
}
