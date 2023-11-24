#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);

  int arr[N];

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &arr[i]);
  }

  int temp[1001] = {0};
  int j = 0;

  for (int i = 0; i < N; i++)
  {
    if (arr[i] == 1)
    {
      j++;
    }
    temp[j]++;
  }

  int total = 0;
  for (int i = 0; i < 1001; i++)
  {
    if (temp[i] != 0)
    {
      total++;
    }
  }

  for (int i = 0; i <= total; i++)
  {
    if (temp[i] != 0)
    {
      if (i == total)
      {
        printf("%d", temp[i]);
      }
      else
      {
        printf("%d ", temp[i]);
      }
    }
  }

  printf("\n");

  return 0;
}