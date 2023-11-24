#include <stdio.h>

int main()
{
  int N;

  scanf("%d", &N);

  int A[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
  }

  int count = 0;

  for (int i = 0; i < N; i++)
  {
    count += A[i];
  }

  printf("%d\n", count);
  return 0;
}