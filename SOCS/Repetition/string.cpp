#include <stdio.h>
#include <string.h>

// int main()
// {
//   char nama[200];
//   scanf("%[^\n]", &nama);
//   int length = strlen(nama);

//   for (int i = length; i > -1; i--)
//   {
//     printf("%c", nama[i]);
//   }
//   return 0;
// }

// int main()
// {
//   char nama[200];
//   scanf("%[^\n]", &nama);

//   int length = 0;

//   for (int i = 0; nama[i] != '\0'; i++)
//   {
//     length++;
//   }

//   int diff = 'a' - 'A';

//   for (int i = 0; i < length; i++)
//   {
//     if (nama[i] >= 'a' && nama[i] <= 'z')
//     {
//       nama[i] = nama[i] - 32;
//     }

//     printf("%c", nama[i]);
//   }

//   return 0;
// }

// int main()
// {
//   char nama[200];
//   scanf("%d", &nama);

//   int length = 0;
//   for (int i = 0; i < nama[i] != '\0'; i++)
//   {
//     length++;
//   }

//   char temp[123];
//   // int temp = 0;
//   for (int i = 0; i < length; i++)
//   {
//     int ascii = nama[i];
//     temp[ascii] = 0;
//   }

//   return 0;
// }

int main()
{
  char string[] = "aldy adalah contoh kalimat";
  int charCount[256] = {0};

  for (int i = 0; string[i] != '\0'; i++)
  {
    if (string[i] != ' ')
    {
      charCount[string[i]]++;
    }
  }

  for (int i = 0; i < 256; i++)
  {
    if (charCount[i] > 0)
    {
      printf("Karakter '%c' muncul sebanyak %d kali dalam string.\n", (char)i, charCount[i]);
    }
  }

  return 0;
}