#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target)
{
  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
      return mid;

    if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}

int main()
{
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 50};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 16;

  int result = binarySearch(arr, 0, n - 1, target);

  if (result != -1)
    printf("Element found at index %d\n", result);
  else
    printf("Element not found in the array\n");

  return 0;
}
