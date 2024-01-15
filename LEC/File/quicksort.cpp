#include <stdio.h>

void printArr(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int kr, int kn)
{
  int pivot = arr[kr];
  int j = kr + 1;

  for (int k = kr + 1; k <= kn; k++)
  {
    if (arr[k] < pivot) // Change the comparison to sort in descending order
    {
      swap(&arr[j], &arr[k]);
      j++;
    }
  }

  swap(&arr[kr], &arr[j - 1]);
  return j - 1;
}

void quickSort(int arr[], int kr, int kn)
{
  if (kr < kn)
  {
    int pivotIndex = partition(arr, kr, kn);
    quickSort(arr, kr, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, kn);
  }
}

int main()
{
  int arr[] = {1, 5, 4, 2};
  int size = 4;
  quickSort(arr, 0, size - 1);
  printArr(arr, size);
  return 0;
}