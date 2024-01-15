#include <stdio.h>

void swap(long long int *a, long long int *b)
{
  long long int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(long long int arr[], int low, int high)
{
  long long int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] >= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

void quicksort(long long int arr[], int low, int high)
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
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int N;
    scanf("%d", &N);
    long long int arr[N];

    for (int j = 0; j < N; j++)
    {
      scanf("%lld", &arr[j]);
    }

    quicksort(arr, 0, N - 1);
    long long int maxSum = arr[0] + arr[1];

    printf("Case #%d: %lld\n", i, maxSum);
  }

  return 0;
}
