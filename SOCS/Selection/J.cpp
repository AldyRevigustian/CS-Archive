
#include <stdio.h>

int main()
{
  int A, B, C;
  scanf("%d %d %d", &A, &B, &C);

  if (A > 100)
  {
    return 0;
  }
  if (B > 100)
  {
    return 0;
  }
  if (C > 100)
  {
    return 0;
  }
  if (A == B && B == C)
  {
    printf("%d\n", 0);
    return 0;
  }

  if (A < C && B > C)
  {
    if (C - A == B - C)
    {
      printf("%d\n", C - A);
    }
    else
    {
      printf("%d\n", -1);
    }
  }
  else
  {
    printf("%d\n", -1);
  }

  return 0;
}