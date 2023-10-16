
#include <stdio.h>

int main()
{
  int a, b, c;
  scanf("%d", &a);
  b = a;
  c = a;
  
  while (b > 0)
  {
    while (a > 0)
    {
      if (b == c || b == 1 || a == c || a == 1)
      {
        printf("*");
      }
      else
      {
        printf(" ");
      }
      a--;
    }

    printf("\n");
    b--;
    a = c;
  }

  return 0;
}