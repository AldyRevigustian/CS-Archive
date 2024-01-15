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

int binarySearch(int arr[], int low, int high, int target)
{
  while (low <= high)
  {
    int mid = low + (mid - low) / 2;

    if (arr[mid] == target)
    {
      return mid;
    }

    if (arr[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return -1;
}

int main()
{
  int arr[10] = {10, 8, 9, 7, 6, 5, 3, 4, 2, 1};

  quicksort(arr, 0, 9);

  for (int i = 0; i < 10; i++)
  {
    printf("%d ", arr[i]);
  }
  

  printf("\n%d", binarySearch(arr, 0, 9, 5));

  return 0;
}