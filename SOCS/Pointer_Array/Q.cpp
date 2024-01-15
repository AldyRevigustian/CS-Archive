#include <stdio.h>

void simulateLights(int T, int N, int M, int Q, int patterns[][50], int visitOrder[])
{
  int lights[50] = {0};

  for (int i = 0; i < Q; i++)
  {
    int friendIndex = visitOrder[i] - 1;
    for (int j = 0; j < M; j++)
    {
      if (patterns[friendIndex][j] == 1)
      {
        lights[j] = 1 - lights[j];
      }
    }
  }

  printf("Case #%d:\n", T);
  for (int i = 0; i < M; i++)
  {
    printf("%s\n", (lights[i] == 1) ? "YES" : "NO");
  }
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++)
  {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);

    int patterns[50][50];
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        scanf("%d", &patterns[i][j]);
      }
    }

    int visitOrder[50];
    for (int i = 0; i < Q; i++)
    {
      scanf("%d", &visitOrder[i]);
    }

    simulateLights(t, N, M, Q, patterns, visitOrder);
  }

  return 0;
}
