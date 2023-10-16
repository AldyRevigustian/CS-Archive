#include <stdio.h>

int main()
{
  int n;
  int A, B;
  scanf("%d", &n);

  int outputs[n];

  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &A, &B);
    outputs[i] = (A / B) << B;
  }

  for (int i = 0; i < n; i++)
  {
    printf("%d\n", outputs[i]);
  }

  return 0;
}
