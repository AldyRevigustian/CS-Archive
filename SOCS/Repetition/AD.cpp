#include <stdio.h>

int main()
{
  int A;
  scanf("%d", &A);

  int B[A];

  for (int i = 0; i < A; i++)
  {
    scanf("%d", &B[i]);
  }

  int count = 0;
  for (int j = 0; j < A; j++)
  {
    // [1, 2, 3, 2, 3, 1]
    // for (int i = j; i < A; i++)
    // {
      if(B[j] == B[1]) printf("Sama");
      if(B[j] == B[2]) printf("Sama");
      if(B[j] == B[3]) printf("Sama");
      if(B[j] == B[4]) printf("Sama");
      if(B[j] == B[5]) printf("Sama");
      if(B[j] == B[0]) printf("Sama");
      // B[j] == B[i + 1]
      // B[0] == B[1]
      // B[1] == B[2]
      // ....
      // B[5] == B[6]
    // }
    
    // if (B[j] == B[j + 1] || B[j] == B[j + j]);
  }
  // printf("%d", count);
  return 0;
}