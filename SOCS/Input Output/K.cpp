#include <stdio.h>

int main() {
    char N[100];
    char A[100];
    char U[8];
    
    scanf("%100[^\n]", N);
    scanf("%s %s", A, U);
    
    
    printf("Name: %s\n", N);
    printf("NIS: %s\n", A);
    printf("Age: %s\n", U);
    
    return 0;
}