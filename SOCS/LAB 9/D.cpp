#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int R, H;
    (void)scanf("%d %d", &R, &H);

    double surface_area = 2 * 3.14 * R * (R + H);

    printf("Case #%d: %.2lf\n", i, surface_area);
  }

  return 0;
}
