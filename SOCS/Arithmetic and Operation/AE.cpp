#include <stdio.h>

int main() {
    long long int N;
    scanf("%d", &N);
    	
    long long int totalKekuatan = 0;
    long long int kekuatanAwal = 100;
    long long int bonusAwal = 0;
    
    for (int i = 0; i < N; i++) {
        totalKekuatan += kekuatanAwal + bonusAwal;
        bonusAwal += 50;
    }
    
    printf("%lld\n", totalKekuatan);
    return 0;
}
