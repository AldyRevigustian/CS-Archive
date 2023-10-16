#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    double R, H;
    double pi = 3.14;

    scanf("%lf %lf", &R, &H);

    double hasil = 2.0 * pi * R * (R + H);

    printf("Case #%d: %.2lf\n", i, hasil);
  }
  
  return 0;
}