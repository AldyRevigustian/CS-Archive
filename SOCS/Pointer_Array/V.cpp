#include <stdio.h>

long long calculateLikes(int N)
{
  if (N == 1)
  {
    return 0;
  }
  else if (N == 2)
  {
    return 1;
  }
  else
  {
    long long a = 0, b = 1, temp;
    for (int i = 3; i <= N; i++)
    {
      temp = a + b;
      a = b;
      b = temp;
    }
    return b;
  }
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int N;
    scanf("%d", &N);

    long long result = calculateLikes(N);
    printf("Case #%d: %lld\n", i, result);
  }

  return 0;
}
