#include <stdio.h>

int main(){
  int A, B;
  scanf("%d %d", &A, &B);

  printf("%.4f%%\n", (float)B / (float)A * 100);

  return 0;
}