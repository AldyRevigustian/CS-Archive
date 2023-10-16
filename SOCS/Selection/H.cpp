#include <stdio.h>

int main()
{
  char X, Y, Z;
  scanf("%c %c %c", &X, &Y, &Z);

  if (X < Y && X < Z)
  {
    if (Y < Z)
    {
      printf("%d %d %d\n", 1, 2, 3);
    }
    else
    {
      printf("%d %d %d\n", 1, 3, 2);
    }
  }
  else if (Y < X && Y < Z)
  {
    if (X < Z)
    {
      printf("%d %d %d\n", 2, 1, 3);
    }
    else
    {
      printf("%d %d %d\n", 2, 3, 1);
    }
  }
  else if (Z < X && Z < Y)
  {
    if (X < Y)
    {
      printf("%d %d %d\n", 3, 1, 2);
    }
    else
    {
      printf("%d %d %d\n", 3, 2, 1);
    }
  }

  return 0;
}
