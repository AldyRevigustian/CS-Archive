#include <stdio.h>

int main()
{
  char T[200];
  scanf("%s", &T);

  int total = 0;
  for (int i = 0; T[i] != '\0'; i++)
  {
    total++;
  }

  int mid = total / 2;
  // mid = 2
  bool isPalindrome = true;
  int diff = 'a' - 'A';

  for (int i = 0; i < mid; i++)
  {
    // total = 5
    // mid = 2

    char left = T[i];
    // char left = T[0];
    // char left = T;
    
    char right = T[total - i - 1];
    // char right = T[5 - 0 - 1];

    if (left >= 'A' && left <= 'Z')
    {
      left += diff;
    }

    if (right >= 'A' && right <= 'Z')
    {
      right += diff;
    }

    if (left != right)
    {
      isPalindrome = false;
      break;
    }
  }

  if (isPalindrome == true)
  {
    printf("%s, Is palindrome", T);
  }
  else
  {
    printf("%s, Is not palindrome", T);
  }

  return 0;
}