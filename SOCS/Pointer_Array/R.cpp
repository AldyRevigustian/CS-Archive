#include <stdio.h>
#include <string.h>

// Function to perform the string transformations
void transformString(char *str, int numQueries, char transformations[][2])
{
  for (int i = 0; i < numQueries; i++)
  {
    char from = transformations[i][0];
    char to = transformations[i][1];

    for (int j = 0; j < strlen(str); j++)
    {
      if (str[j] == from)
      {
        str[j] = to;
      }
    }
  }
}

int main()
{
  int T; // Number of test cases
  scanf("%d", &T);

  for (int t = 1; t <= T; t++)
  {
    char originalString[1001];
    scanf("%s", originalString);

    int M; // Number of queries
    scanf("%d", &M);

    char transformations[M][2];

    for (int i = 0; i < M; i++)
    {
      scanf(" %c %c", &transformations[i][0], &transformations[i][1]);
    }

    transformString(originalString, M, transformations);

    // Output the result for the current test case
    printf("Case #%d: %s\n", t, originalString);
  }

  return 0;
}
