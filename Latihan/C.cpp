#include <stdio.h>
#include <string.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    char S[1001];
    char U[1001];
    int UTemp[123] = {0};
    int STemp[123] = {0};

    scanf("%s", S);
    scanf("%s", U);

    for (int j = 0; U[j] != '\0'; j++)
    {
      UTemp[U[j]]++;
    }

    for (int j = 0; S[j] != '\0'; j++)
    {
      STemp[S[j]]++;
    }

    printf("Case #%d: ", i);

    for (int j = 0; j <= 123; j++)
    {
      if (STemp[j] > 0 && UTemp[j] > 0)
      {
        for (int k = 0; k < STemp[j]; k++)
        {
          printf("%c", j);
        }
      }
    }
    printf("\n");
  }

  return 0;
}