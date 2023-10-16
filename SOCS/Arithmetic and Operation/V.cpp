#include <stdio.h>

int main()
{
  scanf("%d");
  for (int i = 0; i < 3; i++)
  {
    int A;
    scanf("%d", &A);

    double reamur;
    double farenheit;
    double kelvin;

    reamur = (4.0/5.0) * (double)A;
    farenheit = (9.0/5.0) * (double)A + 32;
    kelvin = (double)A + 273.0;
    printf("%.2lf %.2lf %.2lf\n", reamur, farenheit, kelvin);
  }

  return 0;
}