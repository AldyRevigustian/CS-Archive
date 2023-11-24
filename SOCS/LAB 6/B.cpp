#include <stdio.h>

int main()
{
  int ord;
  scanf("%d", &ord);
  int A[ord][ord];

  for (int i = 0; i < ord; i++)
  {
    for (int j = 0; j < ord; j++)
    {
      scanf("%d", &A[i][j]);
    }
  }
  
  bool isSame = false;

  for (int i = 0; i < ord; i++)
  {
    for (int j = 0; j < ord; j++)
    {
      int currentIndex = A[i][j];

      for (int k = j + 1; k < ord; k++)
      {
        if (currentIndex == A[i][k])
        {
          isSame = true;
          break;
        }
      }

      for (int k = i + 1; k < ord; k++)
      {
        if (currentIndex == A[k][j])
        {
          isSame = true;
          break;
        }
      }
    }
  }

  if (isSame == true)
  {
    printf("Nay\n");
  }
  else
  {
    printf("Yay\n");
  }

  return 0;
}