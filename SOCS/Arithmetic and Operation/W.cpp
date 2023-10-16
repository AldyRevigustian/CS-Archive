#include <stdio.h>

int main()
{
  for (int i = 0; i < 3; i++)
  {
    int A;
    scanf("%d", &A);
    printf("%d\n", (A / 10) % 10 );
  }

  return 0;
}