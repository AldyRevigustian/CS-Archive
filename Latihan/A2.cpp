#include <stdio.h>

int main()
{
  FILE *file = fopen("testdata.in", "r");

  while (1)
  {
    int num;
    while (fscanf(file, "%d", &num) != EOF)
    {
      printf("%d", num);

      char nextChar = fgetc(file);

      if (nextChar == '\n' || nextChar == EOF)
      {
        break;
      }
    }
    printf("\n");
    if (feof(file))
    {
      break;
    }
  }

  fclose(file);
  return 0;
}
