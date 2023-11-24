#include <stdio.h>
#include <string.h>

int panjangStr(char stra[])
{
  int pjg = 0;
  for (int i = 0; stra[i] != '\0'; i++) pjg++;

  return pjg;
}
int main()
{
  char nama[100] = "Aldy Revi";

  printf("%d", panjangStr(nama));
  return 0;
}