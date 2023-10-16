#include <stdio.h>
#include <string.h>

int main(){
    // Enkripsi 
    char string[1000];
    scanf("%[^\n]", string);

    int n = strlen(string);

    int enkripsi = 20;
    int diff = 'Z' - 'A' + 1;

    for(int i = 0; i < n; i++){
        int c = string[i];
        int index = c - 'A';
        
        index = index + enkripsi;
        index = index % diff;
        
        string[i] = index + 'A';
    }

    printf("%s", string);


    return 0;
}
