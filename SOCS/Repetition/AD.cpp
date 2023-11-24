#include <stdio.h>

int main()
{
  int A;
  scanf("%d", &A);

  int B[A];
  int temp[1001] = {0};

  for (int i = 0; i < A; i++)
  {
    scanf("%d", &B[i]);
  }

  int count = 0;
  for (int j = 0; j < A; j++)
  {
    temp[B[j]]++;
  }

  int most = 0;
  for (int j = 0; j < 1001; j++)
  {
    if (temp[j] != 0)
    {
      if (temp[j] > most)
      {
        most = temp[j];
      }
    }
  }

  printf("%d\n", most);
  return 0;
}