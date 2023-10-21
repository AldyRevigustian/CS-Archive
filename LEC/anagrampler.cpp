#include <stdio.h>
#include <string.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    char kalimat1[226];
    char kalimat2[226];

    scanf("%s", &kalimat1);
    scanf("%s", &kalimat2);

    int temp1[200] = {};
    int temp2[200] = {};
    int total = 0;
    int cek = 0;

    for (int j = 0; j < strlen(kalimat1); j++)
    {
      temp1[kalimat1[j]]++;
    }

    for (int j = 0; j < strlen(kalimat2); j++)
    {
      temp2[kalimat2[j]]++;
    }

    for (int j = 'a'; j < 'z'; j++)
    {
      if (temp1[j] && temp2[j] == true)
      {
        cek = 1;
        break;
      }
    }

    if (cek == 0)
    {
      printf("Test Case %d: Not Found sayang", i);
    }
    else
    {
      for (int j = 'a'; j < 'z'; j++)
      {
        if (temp1[j] - temp2[j] < 0)
        {
          total = total + ((temp1[j] - temp2[j]) * -1);
        }
        else
        {
          total = total + (temp1[j] - temp2[j]);
        }
      }

      printf("Test Case %d: %d", i, total);
    }
  }

  return 0;
}