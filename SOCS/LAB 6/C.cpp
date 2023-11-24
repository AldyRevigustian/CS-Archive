#include <stdio.h>
#include <string.h>

int main()
{
  char str[501];
  int kasus;
  scanf("%d", &kasus);
  for (int i = 0; i < kasus; i++)
  {
    scanf("%s", str);
    int lenght = strlen(str);
    int palindrome = 1;

    for (int i = 0; i < lenght / 2; i++)
    {

      if (str[i] != str[lenght - i - 1])
      {
        palindrome = 0;
        break;
      }
    }
    if (palindrome)
    {
      printf("Case #%d: Yay, it's a palindrome\n", i + 1);
    }
    else
    {
      printf("Case #%d: Nah, it's not a palindrome\n", i + 1);
    }
  }
  return 0;
}