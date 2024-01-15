#include <stdio.h>

int linearSearch(int arr[], int size, int n)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == n)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  FILE *f = fopen("testdata.in", "r");
  int N;

  fscanf(f, "%d", &N);

  int nim[N];
  char nama[N][21];

  for (int i = 0; i < N; i++)
  {
    fscanf(f, "%d %s\n", &nim[i], nama[i]);
  }

  int D;
  fscanf(f, "%d", &D);
  int searchNim[D];

  for (int i = 0; i < D; i++)
  {
    fscanf(f, "%d\n", &searchNim[i]);
  }

  for (int i = 0; i < D; i++)
  {
    int index = linearSearch(nim, N, searchNim[i]);
    printf("Case #%d: %s\n", i + 1, index == -1 ? "N/A" : nama[index]);
  }

  return 0;
}