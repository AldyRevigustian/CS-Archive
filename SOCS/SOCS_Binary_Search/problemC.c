#include <stdio.h>
#include <stdlib.h>

long long int findIndex(long long int arr[], long long int n, long long int m,long long int sums[]) {
    long long int result = -1;
    long long int left = 0, right = n - 1;

    while (left <= right) {
        long long int mid = left + (right - left) / 2;
        long long int sum = sums[mid+1];

        if (sum <= m) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    long long int N, Q;
    scanf("%lld", &N);
    long long int *B= calloc(N+1, sizeof(long long int));


    long long int *A = (long long int *)malloc(N * sizeof(long long int));
    for (long long int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        if(i<1)continue;
        B[i]=B[i-1]+A[i-1];
    }
    B[N]=B[N-1]+A[N-1];

    scanf("%lld", &Q);


    for (long long int i = 1; i <= Q; i++) {
        long long int M;
        scanf("%lld", &M);

        long long int index = findIndex(A, N, M, B) + 1;
        if (!index) index = -1;

        printf("Case #%lld: %lld\n", i, index);
    }
    return 0;
}
