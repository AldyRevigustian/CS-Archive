#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct
{
  int row;
  int col;
  int distance;
} Node;

int is_valid_move(char grid[N][N], int visited[N][N], int row, int col)
{
  return 0 <= row && row < N && 0 <= col && col < N && grid[row][col] != '#' && !visited[row][col];
}

int bfs(char grid[N][N], int start_row, int start_col, int end_row, int end_col)
{
  int visited[N][N] = {0};
  Node queue[N * N];
  int front = 0, rear = 0;

  Node start = {start_row, start_col, 0};
  queue[rear++] = start;
  visited[start_row][start_col] = 1;

  while (front < rear)
  {
    Node current = queue[front++];

    if (current.row == end_row && current.col == end_col)
    {
      return current.distance;
    }

    int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; ++i)
    {
      int new_row = current.row + moves[i][0];
      int new_col = current.col + moves[i][1];

      if (is_valid_move(grid, visited, new_row, new_col))
      {
        Node next = {new_row, new_col, current.distance + 1};
        queue[rear++] = next;
        visited[new_row][new_col] = 1;
      }
    }
  }

  return -1; // Unable to reach the destination
}

int main()
{
  FILE *file = fopen("testdata.in", "r");
  if (file == NULL)
  {
    perror("Error opening file");
    return 1;
  }

  char grid[N][N];

  // Read the grid from file
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      fscanf(file, " %c", &grid[i][j]);
    }
  }

  fclose(file);

  int start_row, start_col, end_row, end_col;

  // Find the positions of S and E
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      if (grid[i][j] == 'S')
      {
        start_row = i;
        start_col = j;
      }
      else if (grid[i][j] == 'E')
      {
        end_row = i;
        end_col = j;
      }
    }
  }

  int result = bfs(grid, start_row, start_col, end_row, end_col);

  if (result != -1)
  {
    printf("BERHASIL\n");
  }
  else
  {
    printf("GAGAL\n");
  }

  return 0;
}
