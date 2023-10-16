#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);
  
  for (int i = 0; i < 3; i++)
  {
    int A;
    long long int B;
    scanf("%d %lld", &A, &B);
    double bagi =  ((double)A * (double)B) / 360.0;

    printf("%.2lf\n", bagi);
  }

  return 0;
}