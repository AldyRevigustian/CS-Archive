#include <stdio.h>

int jobonacci(int n)
{
  if (n == 0)
  {
    return 0;
  }
  else if (n == 1 || n == 2 || n % 2 == 1)
  {
    return 1;
  }
  else
  {
    return jobonacci(n - 1) + jobonacci(n - 2);
  }
}

int main()
{
  int N;
  scanf("%d", &N);

  printf("%d\n", jobonacci(N));
  return 0;
}
