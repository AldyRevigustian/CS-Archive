#include <stdio.h>
#include <string.h>

struct Siswa
{
  char nama[100];
  int nilai;
};

void swap(Siswa *xp, Siswa *yp)
{
  Siswa temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(Siswa arr[], int n)
{
  int i, j;
  bool swapped;

  for (i = 0; i < n - 1; i++)
  {
    swapped = false;
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j].nilai < arr[j + 1].nilai)
      {
        swap(&arr[j], &arr[j + 1]);
        swapped = true;
      }
    }

    if (swapped == false)
      break;
  }
}

int search(Siswa arr[], int N, const char *x)
{
  
  for (int i = 0; i < N; i++)
  {
    printf("%d\n", strcmp(arr[i].nama, x));
    // if (strcmp(arr[i].nama, x) == 0)
    // {
    //   // printf
    //   printf("%d", i);
    //   return i + 1;
    // }
  }
  return -1;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++)
  {
    int N;
    scanf("%d", &N);
    Siswa listSiswa[N];

    for (int j = 0; j < N; j++)
    {
      scanf("%[^#]#%d", listSiswa[j].nama, &listSiswa[j].nilai);
    }

    bubbleSort(listSiswa, N);

    char searchName[100];
    scanf("%s", searchName);

    int result = search(listSiswa, N, searchName);

    printf("%d\n", result);
  }
  return 0;
}