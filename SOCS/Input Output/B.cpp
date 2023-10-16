#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    
    for(int a=N; a < M+N; a++){
        printf("%d\n", a);
    }
    return 0;
}
