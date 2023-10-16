#include <stdio.h>

int main(){
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  if (a>b && a > c)
  {
    printf("A Paling Besar");
  }else{
    if (b>c)
    {
      printf("B Paling Besar");
    }else{
      printf("C Paling Besar");
    }
  }
  return 0;
}