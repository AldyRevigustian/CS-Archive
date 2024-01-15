#include <stdio.h>
#include <string.h>

const char *jenis_kelamin_pengguna(char username[])
{
  int len = strlen(username);
  int count[26] = {0};

  for (int i = 0; i < len; i++)
  {
    if (username[i] >= 'a' && username[i] <= 'z')
    {
      count[username[i] - 'a'] = 1;
    }
  }

  int jumlah_huruf_berbeda = 0;
  for (int i = 0; i < 26; i++)
  {
    jumlah_huruf_berbeda += count[i];
  }

  if (jumlah_huruf_berbeda % 2 == 0)
  {
    return "Yay";
  }
  else
  {
    return "Ewwww";
  }
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    char username[100001];
    scanf("%s", username);

    const char *result = jenis_kelamin_pengguna(username);
    printf("Case #%d: %s\n", i, result);
  }

  return 0;
}
