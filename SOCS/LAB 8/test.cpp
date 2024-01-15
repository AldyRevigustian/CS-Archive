#include <stdio.h>
#include <string.h>

typedef struct
{
  int nim;
  char nama[1001];
} Student;

void swap(Student *a, Student *b)
{
  Student temp = *a;
  *a = *b;
  *b = temp;
}

void bubleSort(Student arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j].nim > arr[j + 1].nim)
      {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

int main()
{
  FILE *f = fopen("testdata.in", "r");
  int N;
  int index = 0;
  fscanf(f, "%d", &N);
  Student student[N];

  while (!feof(f) && index < N)
  {
    fscanf(f, "%d %s\n", &student[index].nim, student[index].nama);
    index++;
  }

  bubleSort(student, N);

  for (int i = 0; i < N; i++)
  {
    printf("%d %s\n", student[i].nim, student[i].nama);
  }

  return 0;
}
