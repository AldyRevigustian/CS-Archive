#include<stdio.h>
#include<string.h>

int main(){
	// Strlen, Strcmp, Strcpy
	
    // [1] strlen -> hitung panjang sebuah string
	printf("[1] strlen\n");
	char stringA[] = "Hello";
	int strLength = strlen(stringA);
	printf("%s\n", stringA);
	printf("%d\n", strLength);
	
	for(int i = 0; i < strLength; i++){
		printf("1\n");
	}
	
	// [2] strcmp -> perbsndingan untuk string
	printf("\n[2] strcmp\n");
	char str1[] = "Hello";
	char str2[] = "World";
	
	printf("%d\n", strcmp(str1,str2));
    // 0 Jika Benar, -1 Jika Str2 Lebih besar  || 1 Jika Str1 Lebih Besar Secara ASCII JiKa Salah
		
    // strcpy -> copy string
	printf("\n[2] strcmp\n");	
	char string1[] = "Helllo";
	char string2[] = "World";
	
	printf("Sebelum DI COPY : \n");
	printf("%s\n", string1);
	printf("%s\n", string2);
	
	printf("Setelah DI COPY : \n");
	strcpy(string1, "Hello World");
	printf("%s\n", string1);
	printf("%s\n", string2);
	
	return 0;                         	
}
