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

int binarysearch(int arr[], int low, int high, int target)
{
  while (low <= high)
  {
    int mid = low + (high - low) / 2;

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
  FILE *fp = fopen("data.rand", "r");
  int arr[1001];
  int i = 0;

  while (fscanf(fp, "%d", &arr[i]) ==  1)
  {
    i++;
  }

  int size = i;

  printf("Sebelum Sort\n");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\nSetelah Sort\n");
  quicksort(arr, 0, size - 1);

  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  int target;
  printf("\nMasukan angka yang di cari : ");
  scanf("%d", &target);
  printf("ke - %d", binarysearch(arr, 0, size - 1, target));

  return 0;
}