#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int arr[6];
    int letter[6] = {'a', 's', 'h', 'i', 'a', 'p'};

    for (int j = 0; j < 6; j++)
    {
      scanf("%d", &arr[j]);
    }

    printf("Case #%d: ", i);
    for (int j = 0; j < 6; j++)
    {
      for (int k = 0; k < arr[j]; k++)
      {
        printf("%c", letter[j]);
      }
    }
    printf("\n");
  }

  return 0;
}