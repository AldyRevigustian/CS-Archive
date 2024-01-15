#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

int main()
{
  int N;
  scanf("%d", &N);

  int arr[N];

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &arr[i]);
  }

  bubbleSort(arr, N);

  int maxDiff = 0;
  int arrMax[N];

  for (int i = 0; i < N-1; i++)
  {
    // if (i < N - 1)
    // {
      int t = arr[i + 1] - arr[i];
      if (t > maxDiff)
      {
        maxDiff = t;
      }
    // }
  }

  int tmp = 0;
  for (int i = 0; i < N-1; i++)
  {
    // if (i < N - 1)
    // {
      int t = arr[i + 1] - arr[i];
      if (t == maxDiff)
      {
        arrMax[tmp] = arr[i];
        arrMax[tmp + 1] = arr[i + 1];
        tmp += 2;
      }
    // }
  }

  for (int i = 0; i < tmp; i++)
  {
    if (i == tmp - 1)
    {
      printf("%d", arrMax[i]);
    }
    else
    {
      printf("%d ", arrMax[i]);
    }
  }

  printf("\n");
  return 0;
}