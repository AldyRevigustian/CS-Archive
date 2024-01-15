#include <stdio.h>

struct Peserta
{
  int nilai;
  char nama[30];
};

void swap(Peserta *a, Peserta *b)
{
  Peserta t = *a;
  *a = *b;
  *b = t;
}

int partition(Peserta arr[], int low, int high)
{
  int pivot = arr[high].nilai;
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j].nilai < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(Peserta arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int binarySearch(Peserta arr[], int low, int high, int target)
{
  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (arr[mid].nilai == target)
    {
      return mid;
    }
    else if (arr[mid].nilai < target)
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
  int N;
  scanf("%d", &N);
  Peserta listPeserta[N];

  if (N < 8 || N & 4 != 0)
  {
    return 0;
  }

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &listPeserta[i].nilai);
  }

  for (int i = 0; i < N; i++)
  {
    scanf("%s", listPeserta[i].nama);
  }

  quickSort(listPeserta, 0, N - 1);

  int search;
  scanf("%d", &search);

  int klompok = N / 4;
  int letak = N - binarySearch(listPeserta, 0, N - 1, search);
  float letakKelompok = letak / klompok;

  int finalKelompok;

  if (letakKelompok <= 1)
  {
    finalKelompok = 1;
  }
  else if (letakKelompok <= 2)
  {
    finalKelompok = 2;
  }
  else if (letakKelompok <= 3)
  {
    finalKelompok = 3;
  }
  else if (letakKelompok <= 4)
  {
    finalKelompok = 4;
  }
  
  printf("%d %s %d\n", letak, listPeserta[N - letak].nama, finalKelompok);
  return 0;
}