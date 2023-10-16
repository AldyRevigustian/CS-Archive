#include <stdio.h>

int main(){
  int A, B=23, C=12, D=32, E=0;

  A = B && E;
  printf("%d\n", A);
  
  A = B & C;
  printf("%d\n", A);
  
  A = C || D;
  printf("%d\n", A);
  
  A = B | D;
  printf("%d\n", A);
  
  A = B > 2;
  printf("%d\n", A);
  
  A = B >> 2;
  printf("%d\n", A);
  
  A = C < 3;
  printf("%d\n", A);
  
  A = C << 3;
  printf("%d\n", A);
  
  A = B = C;
  printf("%d\n", A);
  
  A = B == C;
  printf("%d\n", A);

  return 0;
}