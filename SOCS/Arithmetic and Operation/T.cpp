#include <stdio.h>

int main()
{
  for (int i = 0; i < 5; i++)
  {
    char A[10];
    int B, D, C, E;
    scanf("%s %d:%d-%d:%d", &A, &B, &C, &D, &E);
    printf("%s %02d:%02d-%02d:%02d\n", A, B - 1, C, D - 1, E);
  }
  return 0;
}