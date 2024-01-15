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

    printf("Case #%d : ", i);
    for (int j = strlen(kata) - 1; j >= 0; j--)
    {
      printf("%c", kata[j]);
    }
    printf("\n");
  }

  return 0;
}