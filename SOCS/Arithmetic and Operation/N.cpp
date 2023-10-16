#include <stdio.h>

int main() {
    long long int A, B;
    scanf("%lld %lld", &A, &B);
    
    double discount = ((double)(A - B) / A) * 100.0;
    
    printf("%.2lf%%\n", discount);
    
    return 0;
}