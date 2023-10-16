#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        
        char S[N + 1];
        scanf(" %[^\n]s", S);
        
        char result[N + 1];
        int idx = 0;
        
        for (int i = 0; i < N; i++) {
            if (S[i] >= 'a' && S[i] <= 'z') {
                result[idx++] = S[i];
            }
        }
        
        result[idx] = '\0';
        
        printf("Case #%d: %s\n", t, result);
    }
    
    return 0;
}
