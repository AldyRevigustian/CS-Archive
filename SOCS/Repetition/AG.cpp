#include <stdio.h>

int main()
{
  int T;

  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    long long int cut;
    scanf("%lld", &cut);

    long long int temp = 1;
    printf("Case %d: ", i);

    for (long long int j = 0; j < cut; j++)
    {
      temp = temp + j;

      if (j == cut - 1)
      {
        printf("%lld", temp);
      }
      else
      {
        printf("%lld ", temp);
      }
    }
    printf("\n");
  }

  return 0;
}