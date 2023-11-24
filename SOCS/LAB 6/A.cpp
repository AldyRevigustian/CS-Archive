#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);
  long long int data[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &data[i]);
  }

  int tamuYangSenang = 0;
  for (int i = 0; i < N; i++)
  {
    int senang = 1;
    for (int j = i + 1; j < N; j++)
    {
      if (data[i] == data[j])
      {
        senang = 0;
        break;
      }
    }
    tamuYangSenang = tamuYangSenang + senang;
  }
  printf("%d\n", tamuYangSenang);

  return 0;
}