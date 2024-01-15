#include <stdio.h>
#include <string.h>

struct Mahasiswa
{
  long long NIM;
  char nama[1000];
  int umur;
  double GPA;
};

int main()
{
  FILE *f = fopen("data.txt", "r");
  Mahasiswa mahasiswaList[2];

  int n = 0;
  printf("Sebelum sorting : \n");

  while (!feof(f))
  {
    fscanf(f, "%lld;%[^;];%d;%lf\n", &mahasiswaList[n].NIM, &mahasiswaList[n].nama, &mahasiswaList[n].umur, &mahasiswaList[n].GPA);
    printf("NIM : %lld, Nama : %s, Umur : %d, GPA : %.2lf\n", mahasiswaList[n].NIM, mahasiswaList[n].nama, mahasiswaList[n].umur, mahasiswaList[n].GPA);
  }

  int size = 2;

  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (mahasiswaList[j].umur > mahasiswaList[j - 1].umur)
      {
        Mahasiswa temp = mahasiswaList[j];
        mahasiswaList[j] = mahasiswaList[j - 1];
        mahasiswaList[j - 1] = temp;
      }
    }
  }

  printf("Setelah sorting : \n");
  for (int i = 0; i < size; i++)
  {
    printf("NIM : %lld, Nama : %s, Umur : %d, GPA : %.2lf\n", mahasiswaList[i].NIM, mahasiswaList[i].nama, mahasiswaList[i].umur, mahasiswaList[i].GPA);
  }

  return 0;
}