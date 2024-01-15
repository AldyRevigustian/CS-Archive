#include <stdio.h>

long pascalTriangle(int n, int i)
{
  if (n == i || i == 0)
    return 1;
  else
    return pascalTriangle(n - 1, i) + pascalTriangle(n - 1, i - 1);
}

int main()
{
  int n, i, j, space = 0;

  printf("Enter the number of lines: ");
  scanf("%d", &n);

  for (i = 0; i <= n; i++)
  {
    for (space = 0; space < n - i; space++)
    {
      printf(" ");
    }

    for (j = 0; j <= i; j++)
    {
      long res = pascalTriangle(i, j);
      printf("%ld ", res);
    }
    printf("\n");
  }
  return 0;
}