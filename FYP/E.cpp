#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int X = 1; X <= T; X++) {
        int K, N, M;
        scanf("%d %d %d", &K, &N, &M);

        if (K <= N + M)
        {
            printf("Case #%d: %s\n", X, "yes");
        }else{
            printf("Case #%d: %s\n", X, "no");
        }
    }

    return 0;
}