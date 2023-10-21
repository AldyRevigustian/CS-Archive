#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int ord;
    scanf("%d", &ord);
    int arr[ord][ord];

    for (int j = 0; j < ord; j++)
    {
      for (int k = 0; k < ord; k++)
      {
        // arr[0][1] = 1
        // arr[0][2] = 2
        // arr[0][3] = 3
        scanf("%d", &arr[j][k]);
      }
    }

    int arrHasil[ord];

    for (int j = 0; j < ord; j++)
    {
      arrHasil[j] = 0;
      for (int k = 0; k < ord; k++)
      {
        // arr[0][0] = 1
        // arr[1][0] = 1
        // arr[2][0] = 1

        arrHasil[j] += arr[k][j];
      }
    }

    printf("Case #%d: ", i);
    for (int j = 0; j < ord; j++)
    {
      if (j == ord - 1)
      {
        printf("%d", arrHasil[j]);
      }
      else
      {
        printf("%d ", arrHasil[j]);
      }
    }

    printf("\n");
  }

  return 0;
}