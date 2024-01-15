#include <stdio.h>

long long binomialCoefficient(int n, int k)
{
  if (k == 0 || k == n)
  {
    return 1;
  }
  else
  {
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
  }
}

void printBabelTowerRow(int n)
{

  for (int k = 0; k <= n; k++)
  {
    printf("%llu ", binomialCoefficient(n, k));
  }
  printf("\n");
}

int main()
{
  // Membaca input dari pengguna
  int n;
  scanf("%d", &n);

  // Menampilkan baris n dari Menara Babel
  printBabelTowerRow(n);

  return 0;
}
