#include<stdio.h>

// [1] Input
// int main(){
// 	int input;
// 	printf("Tolong berikan angka : ", input);	
// 	scanf("%d", &angka);

// 	printf("Angka yang diinput adalah %d", input);
// 	return 0;	
// }

// [2] Escape 
// int main(){
// 	printf("1.Roti\n2.Bakso\n3.Anggur")
// 	printf("\t1.Roti 2.Bakso 3.Anggur")
// 	return 0;
// }

// [3] DataType
// int main(){
// 	// max integer 2147483647
// 	int integer; 
// 	printf("\nInteger : %d", integer);

// 	// Long Integer
// 	printf("\nInteger : %ld", integer);
	
// 	// Long Long Integer
// 	printf("\nInteger : %lld", integer);
	
// 	// char menggunakan quote satu
// 	char character = 'A';
// 	printf("\nCharacter : %c", character);
	
// 	bool boolean = true;
// 	printf("\nBoolean : %d", boolean);
	

// 	float float_angka = 0.5;
// 	// printf("\nFloat : %f", float);
// 	printf("\nFloat : %.1f", float_angka);
	
// 	double double_angka = 0.5;
// 	// printf("\ndouble : %lf", double);
// 	printf("\ndouble : %.1lf", double_angka);
	
// 	// Unsigned Mengkali 2 batas integer
// 	unsigned int uints = 3147483647;
// 	printf("\nUnsigned : %u", uints);\
// 	// Long unsigned
// 	printf("\nUnsigned : %lu", uints);
// 	// Long Long unsigned
// 	printf("\nUnsigned : %llu", uints);

// 	// Datatype Typecast
// 	int typeCast = (int)2.8;
// 	int floatCast = (float)30;
// 	long longCast = (long)1237817;

// 	int char_a = (int)'a';
	
// 	return 0;
// }


// [4] Library
- stdio.h
	printf()
	puts() // print langung nge enter njir tapi cuman bisa string
	scanf()
	getchar() // Mengambil space biar pas enter kaga langsung ke end program nya

- math.h
	sqrt()
	ceil()
	floor()
	pow()

- stdlib.h
	atof() // Array to float
	atoi() // Array to integer
	abs() // absolute