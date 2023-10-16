#include <stdio.h>

int main()
{
  char str[10];
  scanf("%s", &str);
  int length = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    length++;
  }

  printf("%d\n", length);

  str[0] = str[0] - 32;
  for (int i = length - 1; i >= 0; i--)
  {
    printf("%c", str[i]);
  }

  return 0;
}