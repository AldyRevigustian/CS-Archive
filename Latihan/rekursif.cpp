#include <stdio.h>

int factorial(int i)
{
  if (i == 1)
  {
    return 1;
  }
  else
  {
    return i * factorial(i - 1);
  }
}

int main()
{
  int N;
  scanf("%d", &N);

  printf("%d", factorial(N));
  return 0;
}