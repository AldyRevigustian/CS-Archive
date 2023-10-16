
#include <stdio.h>

int main()
{
  int a, b, c;
  scanf("%d", &a);
  b = 3;
  c = a;

  while (b > 0)
  {
    printf("*");
    while (a > 0)
    {
      printf("*");
      a--;
    }
    printf("\n");
    b--;
    a = c;
  }

  return 0;
}