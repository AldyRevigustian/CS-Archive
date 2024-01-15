#include <stdio.h>

struct Mahasiswa
{
  char nama[30];
  int umur;
  int tinggi;
};

int main()
{
  FILE *fp = fopen("data.in", "r");

  Mahasiswa mhsList[20];
  int index;

  while (fscanf(fp, " %[^,],%d,%d", mhsList[index].nama, &mhsList[index].umur, &mhsList[index].tinggi) == 3)
  {
    index++;
  }
  fclose(fp);

  FILE *fs = fopen("dataOut.in", "a");

  for (int i = 0; i < index; i++)
  {
    fprintf(fs, "%s, %d, %d\n", mhsList[i].nama, mhsList[i].umur, mhsList[i].tinggi);
  }
  return 0;
}