#include <stdio.h>

int count;
int Floodrow, Floodcolumn;
char peta[105][105];

void FloodFill(int row, int column)
{
  if (peta[row][column] == '#' || peta[row][column] == '\n' || peta[row][column] == '\0' || row < 0 || column < 0)
  {
    return;
  }

  if (peta[row][column] == '.')
  {
    count++;
  }

  peta[row][column] = '#';

  FloodFill(row + 1, column);
  FloodFill(row - 1, column);
  FloodFill(row, column + 1);
  FloodFill(row, column - 1);
}

int main()
{
  int testcase;
  scanf("%d", &testcase);
  for (int k = 1; k <= testcase; k++)
  {
    int row, column;
    scanf("%d %d", &row, &column);

    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < column + 1; j++)
      {
        scanf("%c", &peta[i][j]);
        if (peta[i][j] == 'S')
        {
          Floodrow = i;
          Floodcolumn = j;
        }
      }
    }

    FloodFill(Floodrow, Floodcolumn);
    printf("Case #%d: %d\n", k, count);
    count = 0, Floodrow = 0, Floodcolumn = 0;
    for (int i = 0; i < 105; i++)
    {
      for (int j = 0; j < 105; j++)
      {
        peta[i][j] = '\0';
      }
    }
  }

  return 0;
}