#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

void quicksort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}
int main()
{
  FILE *fp = fopen("data.ins", "r");
  int temp[1001][3];
  int i = 0;

  while (fscanf(fp, "%d %d %d", &temp[i][0], &temp[i][1], &temp[i][2]) == 3)
  {
    i++;
  }

  int arr[i];

  for (int j = 0; j < i; j++)
  {
    arr[j] = temp[j][0] + temp[j][1] + temp[j][2];
  }

  quicksort(arr, 0, i - 1);

  printf("%d\n", arr[0] + arr[i - 1]);

  return 0;
}