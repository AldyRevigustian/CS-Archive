#include <stdio.h>
#include <string.h>

int main()
{
  for (int l = 0; l < 3; l++)
  {
    int N;
    scanf("%d", &N);
    char S[N + 1];

    scanf("%s", S);
    if (N < 2 || strlen(S) < 2)
    {
      return 0;
    }

    printf("%c%c\n", S[strlen(S) - 1], S[0]);
  }

  return 0;
}