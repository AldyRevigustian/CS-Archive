#include <stdio.h>

int main(){
  int A;
  scanf("%d", &A);

  if (A % 2 == 0)
  {
    printf("%s\n", "EVEN");
  }else{
    printf("%s\n", "ODD");
  }
  
  return 0;
}