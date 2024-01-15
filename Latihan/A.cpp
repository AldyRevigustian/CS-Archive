#include <stdio.h>

int main()
{
  int num;
  int index = 0;
  int ganjilTemp = 0;
  int genapTemp = 1;

  FILE *fp = fopen("testdata.in", "r");
  while (fscanf(fp, "%d", &num) == 1)
  {
    if (num % 2 == 0)
    {
      genapTemp *= num;
    }
    else
    {
      ganjilTemp += num;
    }
  }

  fclose(fp);


  printf("%d\n", genapTemp - ganjilTemp);
  return 0;
}