#include <stdio.h>
#include <string.h>

int main()
{

  int t, breath, alive, j;
  char k[11000];
  char hallway[11000];
  int length;
  int temp;
  scanf("%ld", &t);
  for (int i = 1; i <= t; i++)
  {
    alive = 0;
    scanf("%d %d", &length, &breath);
    temp = breath;
    scanf("%s", hallway);
    for (j = 0; j < length; j++)
    {
      if (hallway[j] == '0')
      {
        temp--;
      }
      else
      {
        temp = breath;
        alive = 1;
        break;
      }

      if (temp == 0)
      {
        alive = -1;
        break;
      }
    }
    if (alive == 1)
    {
      for (int k = length - 1; k > j; k--)
      {
        if (hallway[k] == '0')
        {
          temp--;
        }
        else
        {
          alive = 2;
          break;
        }
        if (temp == 0)
        {
          alive = -1;
          break;
        }
      }
    }
    printf("Case #%d: ", i);
    if (length <= breath)
    {
      alive = 2;
    }
    if (alive == 2)
    {
      printf("Alive");
    }
    else
    {
      printf("Dead");
    }
    printf("\n");
  }
  return 0;
}