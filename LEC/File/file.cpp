#include <stdio.h>

int main()
{
  FILE *f = fopen("data.txt", "r");
  // for (int i = 1; i <= 5; i++)
  // {
  //   fprintf(f, "halo aldy;%d\n", i);
  // }

  // fclose(f);

  // FILE *fp = fopen("data.txt", "r");

  long long nim;
  char nama[100];
  int umur;
  float ipk;

  // while (fscanf(fp, "%s", &s) != EOF)
  // {
  //   printf("%s\n", s);
  // }
  // while (!feof(f))
  // {
  //   fscanf(fp, "%s\n", &s);
  //   printf("%s\n", s);
  // }
  
  while (fscanf(f, "%lld;%[^;];%d;%f", &nim, &nama, &umur, &ipk) != EOF)
  {
    // fscanf(f, "%lld;%[^;];%d;%lf\n", &nim, &nama, &umur, &ipk);
    printf("NIM : %lld, Nama : %s, Umur : %d, GPA : %.2f\n", nim, nama, umur, ipk);
  }

  fclose(f);
  return 0;
}