#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int byk;
    scanf("%d", &byk);

    int angka[byk];
    for (int j = 0; j < byk; j++)
    {
      scanf("%d", &angka[j]);
    }

    int yes = 0;
    int no = 0;
    int temp = 0;

    for (int j = 0; j < byk; j++)
    {
      for (int k = 0; k < byk; k++)
      {
        // if (1 == 1) erorrz
        // if (arr[0] == arr[0]) erorrz
        // if (j >= k) erorrz

        // arr[0] ^ arr [0]
        // arr[j] ^ arr [k]
        // arr[0] ^ arr [2]
        // arr[1] ^ arr [2]
        // arr[j] ^ arr[j+1]

        int jmlYes = 0;

        if (j >= k)
        {
          continue;
        }
        else
        {
          temp = angka[j] ^ angka[k];
          int tempCopy = temp;

          while (tempCopy > 0)
          {
            if (tempCopy & 1)
            {
              jmlYes++;
            }
            tempCopy >>= 1;
          }
        }

        if (jmlYes >= 3)
        {
          yes++;
        }
        else
        {
          no++;
        }
      }
    }

    printf("Case #%d: %d %d\n", i, yes, no);
  }

  return 0;
}