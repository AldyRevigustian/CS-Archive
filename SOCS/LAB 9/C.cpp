#include <stdio.h>
int main()
{
  FILE *f = fopen("testdata.in", "r");
  int tc;
  fscanf(f, "%d", &tc);

  for (int t = 1; t <= tc; t++)
  {
    int N, A, B;
    fscanf(f, "%d %d %d", &N, &A, &B);
    char petir[N + 1];
    int count = 0;
    int strike = 0;
    fscanf(f, "%s", petir);

    for (int i = 0; i < N; i++)
    {
      if (petir[i] == '1')
      {
        strike++;
      }
      else
      {
        if (strike >= A && strike <= B)
        {
          count++;
        }
        strike = 0;
      }
    }
    if (strike >= A && strike <= B)
    {
      count++;
    }

    printf("Case #%d: %d\n", t, count);
  }

  fclose(f);

  return 0;
}
