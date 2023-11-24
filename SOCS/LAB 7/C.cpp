#include <stdio.h>

int main()
{
  int X, Y, T, a, b, c;
  scanf("%d %d", &X, &Y);
  int garden[X][Y];
  for (int i = 0; i < X; i++)
  {
    for (int j = 0; j < Y; j++)
    {
      scanf("%d", &garden[i][j]);
    }
  }
  scanf("%d", &T);
  for (int i = 0; i < T; i++)
  {
    scanf("%d %d %d", &a, &b, &c);
    garden[a - 1][b - 1] = c;
  }
  for (int i = 0; i < X; i++)
  {
    for (int j = 0; j < Y; j++)
    {
      if (j == Y - 1)
      {
        printf("%d", garden[i][j]);
      }
      else
      {
        printf("%d ", garden[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}
