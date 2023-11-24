#include <stdio.h>
#include <string.h>

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    int N, M;
    scanf("%d %d", &N, &M);
    int doors[N + 1];
    memset(doors, 0, sizeof(doors));
    for (int m = 0; m < M; m++)
    {
      int X;
      scanf("%d", &X);
      for (int i = X; i <= N; i += X)
      {
        doors[i] = !doors[i];
      }
    }
    printf("Case #%d:", t);
    int open = 0;
    for (int i = 1; i <= N; i++)
    {
      if (!doors[i])
      {
        printf(" %d", i);
        open = 1;
      }
    }
    if (!open)
    {
      printf(" No room left!");
    }
    printf("\n");
  }
  return 0;
}
