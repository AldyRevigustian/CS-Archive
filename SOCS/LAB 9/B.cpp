#include <stdio.h>
#include <string.h>
int main()
{
  int tc;
  scanf("%d", &tc);
  getchar();
  for (int t = 1; t <= tc; t++)
  {
    char s[1001];
    scanf("%[^\n]", s);
    getchar();
    int length = strlen(s);

    printf("Case #%d: ", t);
    for (int i = 0; i < length; i++)
    {
      if (s[i] != 'a' && s[i] != 'A' && s[i] != 'e' && s[i] != 'E' && s[i] != 'i' && s[i] != 'I' && s[i] != 'o' && s[i] != 'O' && s[i] != 'u' && s[i] != 'U')
      {
        printf("%c", s[i]);
      }
    }
    printf("\n");
  }

  return 0;
}
