#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  if (T < 1 || T > 2000)
  {
    return 0;
  }

  int K[T];
  for (int i = 0; i < T; i++)
  {
    scanf("%d", &K[i]);
    if (K[i] < 2 || K[i] > 12)
    {
      return 0;
    }
  }

  int total = 0;
  for (int i = 0; i < T; i++)
  {
    total = total + K[i];
    if (total == 9)
      total = 21;
    if (total == 33)
      total = 42;
    if (total == 76)
      total = 92;
    if (total == 53)
      total = 37;
    if (total == 80)
      total = 59;
    if (total == 97)
      total = 88;
  }

  printf("%d\n", total);
  return 0;
}