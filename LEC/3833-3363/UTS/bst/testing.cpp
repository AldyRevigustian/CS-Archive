#include <stdio.h>

void changeNum(int *num){
  *num += 10;
}

int main(){
  int num = 0;

  changeNum(&num);
  printf("%d",num);

  return 0;
}