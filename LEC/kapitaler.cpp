#include <stdio.h>
#include <string.h>

int main()
{
  char kalimat[200];

  scanf(" %[^\n]", &kalimat);

  if (kalimat[0] >= 'a' && kalimat[0] <= 'z')
  {
    kalimat[0] = kalimat[0] - 32;
  }

  for (int i = 0; kalimat[i] != '\0'; i++)
  {
    if (kalimat[i] == ' ')
    {
      if (kalimat[i + 1] >= 'a' && kalimat[i + 1] <= 'z')
      {
        kalimat[i + 1] = kalimat[i + 1] - 32;
      }
    }
  }

  for (int i = 0; i < strlen(kalimat); i++)
  {
    printf("%c", kalimat[i]);
  }

  return 0;
}