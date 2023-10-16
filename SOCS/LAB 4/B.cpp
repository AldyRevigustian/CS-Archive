#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int result[T];

    for (int t = 0; t < T; t++) {
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);

        int porsi[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &porsi[i]);
        }

        int maxPorsi = K;
        for (int i = 0; i < N; i++) {
            if (porsi[i] <= M) {
                maxPorsi = (porsi[i] > maxPorsi) ? porsi[i] : maxPorsi;
            }
        }

        result[t] = maxPorsi;
    }

    for (int t = 0; t < T; t++) {
        printf("Case #%d: %d\n", t + 1, result[t]);
    }

    return 0;
}