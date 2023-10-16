#include <stdio.h>

int main()
{
    long long int hasil, hasil1, hasil2;
    long long int A, B, C, D;
    long long int A1, B1, C1, D1;
    long long int A2, B2, C2, D2;
    
    scanf("(%lld+%lld)x(%lld-%lld)", &A, &B, &C, &D); getchar();
    scanf("(%lld+%lld)x(%lld-%lld)", &A1, &B1, &C1, &D1); getchar();
    scanf("(%lld+%lld)x(%lld-%lld)", &A2, &B2, &C2, &D2); getchar();
    
    hasil = (A+B)*(C-D);
    hasil1 = (A1+B1)*(C1-D1);
    hasil2 = (A2+B2)*(C2-D2);
    printf("%lld %lld %lld\n", hasil, hasil1, hasil2);

    return 0;
}