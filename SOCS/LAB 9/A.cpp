#include <stdio.h>

long long reverseNumber(long long num)
{
  long long reversed = 0;
  while (num > 0)
  {
    reversed = reversed * 10 + num % 10;
    num /= 10;
  }
  return reversed;
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    long long N;
    scanf("%lld", &N);

    long long reversedN = reverseNumber(N);
    long long JojoNumber = N + reversedN;

    printf("Case #%d: %lld\n", i, JojoNumber);
  }

  return 0;
}
