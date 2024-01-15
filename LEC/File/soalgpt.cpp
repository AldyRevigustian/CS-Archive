#include <stdio.h>
int binarySearch(int arr[], int low, int high, int target)
{
  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] < target)
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

int main(){
  int T;  
  scanf("%d", &T);
  int arr[T];
  for (int i = 0; i < T; i++)
  {
    scanf("%d", &arr[i]);
  }
  
  printf("%d\n", binarySearch(arr, 0, T - 1, 5));
  printf("%d\n", linearSearch(arr, T, 5));

  return 0;
}