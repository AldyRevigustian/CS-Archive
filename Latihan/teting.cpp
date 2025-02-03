#include <stdio.h>


int findMin(int a, int b) {
    return (a < b) ? a : b;
}
int main()
{
  int N;
  scanf("%d", &N);

  int memo[1000];

  memo[0] = 0;

  for (int i = 1; i <= N; i++)
  {
    memo[i] = memo[i - 1] + 1;
    if(i >= 3) memo[i] = findMin(memo[i], memo[i-3] + 1);
    if(i >= 4) memo[i] = findMin(memo[i], memo[i-4] + 1);
    printf("%d : %d\n", i, memo[i]);
  }

  printf("%d\n", memo[N]);

  return 0;
}