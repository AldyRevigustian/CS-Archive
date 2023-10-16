#include <stdio.h>
#include <string.h>

int main()
{
    char string[1000];
    scanf("%s", string);
    int n = strlen(string);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int index = string[i] - '0';
        sum += index;
    }
    printf("%d", sum);
    return 0;
}
