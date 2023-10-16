#include <stdio.h>
#include <string.h>

int main(){
    char nama[101];
    // scanf("%s", &nama);
    scanf("%[^\n]", &nama);
    getchar();
	// ^ -> ignore, \n -> ngambil sampai ketemu \n
	int n = strlen(nama);
    int leng = 0;
    for(int i = 0; nama[i] != '\0'; i++){
        leng += 1;
    }
    
    // Length
    // printf("%d", leng);
    // scanf(nama);

    int mid = leng / 2;

    for(int i=0; i<mid; i++){
        char temp = nama[i];
        nama[i] = nama[n-i-1];
        nama[n-i-1] = temp;
    }

    printf("%s", nama);
    return 0;
}
