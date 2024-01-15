#include <stdio.h>

int main()
{
  int X, Y;
  scanf("%d %d", &X, &Y);
  int arr[X][Y];

  for (int i = 0; i < X; i++)
  {
    for (int j = 0; j < Y; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++)
  {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    arr[A - 1][B - 1] = C;
  }

  for (int i = 0; i < X; i++)
  {
    for (int j = 0; j < Y; j++)
    {
      if (j != Y - 1)
      {
        printf("%d ", arr[i][j]);
      }
      else
      {
        printf("%d", arr[i][j]);
      }
    }
    printf("\n");
  }

  return 0;
}