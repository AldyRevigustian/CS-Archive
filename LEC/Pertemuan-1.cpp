#include <stdio.h>

int main()
{

  // int panjang, lebar, luas;
  // panjang = 5;
  // lebar = 3;

  // luas = panjang * lebar;

  // printf("%d", luas);

  int jam, menit, detik;

  scanf("%d", &detik);

  jam = detik / 3600;
  detik = detik - (jam * 3600);
  menit = detik / 60;
  detik = detik - (menit * 60);

  printf("%d %d %d", jam, menit, detik);

  return 0;
}