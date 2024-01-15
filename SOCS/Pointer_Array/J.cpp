#include <stdio.h>
#include <string.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    char kata[1001];
    scanf("%s", kata);

    printf("Case %d: ", i);

    for (int j = 0; j < strlen(kata); j++)
    {
      if (j != strlen(kata) - 1)
      {
        printf("%d-", kata[j]);
      }
      else
      {
        printf("%d", kata[j]);
      }
    }
    printf("\n");
  }

  return 0;
}
