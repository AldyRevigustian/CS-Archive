#include <stdio.h>

int main(){
  int M, N;
  scanf("%d %d", &M, &N);

  for (int i = M; i < N + M; i++)
  {
    printf("%d\n", i);
  }
  return 0;
}