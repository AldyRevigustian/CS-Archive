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
    int leng = strlen(kata);
    int arr[leng] = {0};

    for (int j = 0; j < leng; j++)
    {
      if (kata[j] >= 'A' && kata[j] <= 'D')
      {
        arr[j] = kata[j] - 'A';
        kata[j] = 'A';
      }
      else if (kata[j] >= 'E' && kata[j] <= 'H')
      {
        arr[j] = kata[j] - 'E';
        kata[j] = 'E';
      }
      else if (kata[j] >= 'I' && kata[j] <= 'N')
      {
        arr[j] = kata[j] - 'I';
        kata[j] = 'I';
      }
      else if (kata[j] >= 'O' && kata[j] <= 'T')
      {
        arr[j] = kata[j] - 'O';
        kata[j] = 'O';
      }
      else if (kata[j] >= 'U' && kata[j] <= 'Z')
      {
        arr[j] = kata[j] - 'U';
        kata[j] = 'U';
      }
    }

    printf("Case #%d:\n", i);
    for (int j = 0; j < leng; j++)
    {
      printf("%c", kata[j]);
    }
    printf("\n");
    for (int j = 0; j < leng; j++)
    {
      printf("%d", arr[j]);
    }
    printf("\n");
    }

  return 0;
}