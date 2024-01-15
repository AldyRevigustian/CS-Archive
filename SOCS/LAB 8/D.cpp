#include <stdio.h>
#include <string.h>

typedef struct
{
  char id[11];
  char name[21];
} Student;

void swap(Student *xp, Student *yp)
{
  Student temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(Student arr[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (strcmp(arr[j].id, arr[j + 1].id) > 0)
        swap(&arr[j], &arr[j + 1]);
}

int main()
{
  int N;
  FILE *file = fopen("testdata.in", "r");
  fscanf(file, "%d\n", &N);
  Student students[N];

  for (int i = 0; i < N; i++)
  {
    fscanf(file, "%s %s\n", students[i].id, students[i].name);
  }

  bubbleSort(students, N);

  for (int i = 0; i < N; i++)
  {
    printf("%s %s\n", students[i].id, students[i].name);
  }

  fclose(file);
  return 0;
}
