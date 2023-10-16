#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 1; i <= t; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        
        int cashback = (a * b) / 100;
        if (cashback > c) {
            cashback = c;
        }
        
        printf("Case #%d: %d\n", i, cashback);
    }
    
    return 0;
}
