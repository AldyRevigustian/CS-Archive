#include <stdio.h>

int main(){
  int A;
  scanf("%d", &A);
  int plus = A + A;
  int minus = plus - 1;

  printf("%d plus %d is %d\n", A, A , plus);
  printf("minus one is %d\n", minus);
  return 0;
}