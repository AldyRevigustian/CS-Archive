#include <stdio.h>
#include <ctype.h>


int main()
{
  char a[100];
  scanf("%s", a);

  *a = toupper(*a);
  printf("Halo %s\n", a);

  return 0;
}