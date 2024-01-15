#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int A, B;
    scanf("%d %d", &A, &B);

    int hasil = 0;
    int pembagi = 1;

    while (A > 0 || B > 0)
    {
      int digitA;
      int digitB;

      digitA = A % 10;
      digitB = B % 10;

      hasil += ((digitA + digitB) % 10) * pembagi;
      pembagi *= 10;

      A /= 10;
      B /= 10;
    }

    printf("Case #%d: %d\n", i, hasil);
  }

  return 0;
}
