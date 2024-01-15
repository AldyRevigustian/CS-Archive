#include <stdio.h>

// Fungsi untuk menggabungkan dua bagian terurut dari array
void merge(int arr[], int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Buat array sementara untuk menyimpan bagian kiri dan kanan
  int L[n1], R[n2];

  // Salin data ke array sementara L[] dan R[]
  for (i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  // Gabungkan kembali array L[] dan R[] ke dalam array utama arr[]
  i = 0;    // Indeks awal array kiri
  j = 0;    // Indeks awal array kanan
  k = left; // Indeks awal array hasil gabungan
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Salin sisa elemen dari L[], jika ada
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Salin sisa elemen dari R[], jika ada
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Fungsi utama untuk melakukan Merge Sort pada array
void mergeSort(int arr[], int left, int right)
{
  if (left < right)
  {
    // Temukan titik tengah array
    int mid = left + (right - left) / 2;

    // Panggil rekursif Merge Sort untuk bagian kiri dan kanan
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Gabungkan dua bagian yang sudah diurutkan
    merge(arr, left, mid, right);
    // merge({12, 11, 13, 5, 6, 7}, 0, 2, 5);
  }
}

// Fungsi untuk mencetak array
void printArray(int A[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d ", A[i]);
  printf("\n");
}

// Program utama
int main()
{
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("Array sebelum diurutkan: \n");
  printArray(arr, arr_size);

  // Panggil fungsi Merge Sort
  mergeSort(arr, 0, arr_size - 1);

  printf("\nArray setelah diurutkan: \n");
  printArray(arr, arr_size);

  return 0;
}
