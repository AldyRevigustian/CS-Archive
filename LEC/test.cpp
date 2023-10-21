#include <stdio.h>
#include <string.h>

int main()
{
  char kalimat[200];

  scanf(" %[^\n]", &kalimat);

  int spasi = 1;

  for (int i = 0; kalimat[i] != '\0'; i++)
  {
    if (kalimat[i] == ' ')
    {
      spasi++;
    }
  }

  int bagi = strlen(kalimat) / spasi;

  if (kalimat[0] >= 'a' && kalimat[0] <= 'z')
  {
    kalimat[0] = kalimat[0] - 32;
  }

  if (strlen(kalimat) % 2 == 0)
  {
    if (kalimat[bagi] >= 'a' && kalimat[bagi] <= 'z')
    {
      kalimat[bagi] = kalimat[bagi] - 32;
    }
  }
  else
  {
    if (kalimat[bagi + 1] >= 'a' && kalimat[bagi + 1] <= 'z')
    {
      kalimat[bagi + 1] = kalimat[bagi + 1] - 32;
    }
  }

  for (int i = 0; i < strlen(kalimat); i++)
  {
    printf("%c", kalimat[i]);
  }

  return 0;
}

// go ok
//  0 1 2 3
