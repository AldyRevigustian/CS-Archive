#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    char ch[100001];
    scanf("%s", ch);

    int tmp[123] = {};
    int beda = 0;
    for (int j = 0; ch[j] != '\0'; j++)
    {
      tmp[ch[j]]++;
    }

    for (int j = 0; j < 123; j++)
    {
      if (tmp[j] != 0)
      {
        beda++;
      }
    }

    if (beda % 2 == 0)
    {
      printf("Case #%d: Breakable\n", i);
    }
    else
    {
      printf("Case #%d: Unbreakable\n", i);
    }
  }

  return 0;
}