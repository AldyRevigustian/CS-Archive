#include <stdio.h>
#include <string.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int N;
    char arr[1001];
    scanf("%d", &N);
    scanf("%s", &arr);
    int leng = strlen(arr);

    for (int j = 0; j < N; j++)
    {
      int A, B;
      scanf("%d %d", &A, &B);

      char temp[1001];
      strcpy(temp, arr);

      int var = A - 1;
      for (int k = B - 1; k >= A - 1; k--)
      {
        char tmp = arr[var];
        arr[var] = temp[k];
        var++;
      }
    }

    printf("Case #%d: ", i);
    for (int j = 0; j < leng; j++)
    {
      printf("%c", arr[j]);
    }
    printf("\n");
  }

  return 0;
}