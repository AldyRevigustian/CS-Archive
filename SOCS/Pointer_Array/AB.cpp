#include <stdio.h>

void multiplyMatrices(int mat1[50][50], int mat2[50][50], int result[50][50], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int testCase = 1; testCase <= T; testCase++) {
        int N;
        scanf("%d", &N);

        int mat1[50][50], mat2[50][50], mat3[50][50], result[50][50];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &mat1[i][j]);
            }
        }

        // Membaca matrix kedua
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &mat2[i][j]);
            }
        }

        // Membaca matrix ketiga
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &mat3[i][j]);
            }
        }

        // Mengalikan ketiga matrix secara berurutan
        int temp[50][50];
        multiplyMatrices(mat1, mat2, temp, N);
        multiplyMatrices(temp, mat3, result, N);

        // Menampilkan output
        printf("Case #%d:\n", testCase);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d", result[i][j]);
                if (j < N - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Membaca baris kosong di antara test case
        // if (testCase < T) {
        //     printf("\n");
        // }
    }

    return 0;
}
