#include <stdio.h>

int main()
{
  scanf("%d");
  for (int i = 0; i < 3; i++)
  {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    double hasil = 2*((double)A/1) + 4*((double)B/2) + 4*((double)C/3)+ 2*((double)D/4);
    printf("%.2lf\n", hasil);
  }
  return 0;
}