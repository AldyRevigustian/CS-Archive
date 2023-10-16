#include<stdio.h>

int main(){
	int x = 10;
	int y = 5;

	// === Arithmetic Operator ===
	// 1. Penjumlahan (+)
	// 2. Pengurangan (-)
	// 3. Perkalian (*)
	// 4. Pembagian (/)
	// 5. Modulo (%)
	printf("Arithmetic Operator\n");

	printf("Penjumlahan x + y :  %d\n", x+y);
	printf("Pengurangan x - y :  %d\n", x-y);
	printf("Perkalian x * y :  %d\n", x*y);
	printf("Pembagian x / y :  %d\n", x/y);
	printf("Modulo x % y :  %d\n", x%y);
	
	// === Precedence and Associative Operator ===
	// (5 + 2) - 5 * 2
	// KurKaliBaTaKu
	printf("\n");
	printf("Precedence and Associative Operator\n");

	printf("Precedence (x+y) - x*y : %d\n", (x+y) - x*y);

	// === Assignment Operator (=) ===
	printf("\n");
	printf("Assignment Operator\n");

	x = x + 5;
	printf("x = %d\n", x); 
	
	// === Shorthand Operator ===
	printf("\n");
	printf("Shorthand Operator\n");

	x += 5;	
	printf("x += 5 : %d\n", x); 
	
	x -= 5;
	printf("x -= 5 : %d\n", x); 
	
	x *= 5;
	printf("x *= 5 : %d\n", x); 
	
	x /= 5;
	printf("x /= 5 : %d\n", x); 
	
	x %= 5;
	printf("x %= 5 : %d\n", x); 
	

	// === Relational Operator ===
	// ==, !=, >, <, >=, <=
	printf("\n");

	x = 30;
	y = 30;

	printf("x = %d\n", x);
	printf("y = %d\n", y);

	printf("\n");
	printf("Relational Operator\n");

	printf("x == y : %d\n", x == y);
	printf("x != y : %d\n", x != y);
	printf("x > y : %d\n", x > y);
	printf("x < y : %d\n", x < y);
	printf("x >= y : %d\n", x >= y);
	printf("x <= y : %d\n", x <= y);

	
	// === Logical Operator ===
	// &&(dan) ||(atau)
	printf("\n");
	printf("Logical Operator\n");

	printf("x == 30 && y == 30 : %d\n", x == 30 && y == 30);
	printf("x == 30 || y == 20 : %d\n", x == 30 || y == 20);
	

	// === Bitwise Operator === 
	
	
	printf("\n");
	printf("Bitwise Operator\n");
	
	x = 10;
	y = 5;

	// 1 byte = 8 bit

	// 00000000 00000000 00000000 00000101 = 5
	
	// 101
	// (2^2)(2^1)(2^0) 
	// 101 == 5

	// 1. AND (&)
	// 2. OR (|)
	// 3. XOR (^)
	// 4. NOR (~)
	// 5. Shift left (<<)
	// 6. Shift Right (>>)
	
	printf("Bitwise 10 & 2 : %d\n", 10 & 2);
	// 1 0 1 0  ==  10
	// 0 1 0 1  ==  5
	// -------   
	// 0 0 0 0  == 0
	
	printf("Bitwise 10 & 7 : %d\n", 10 & 7);
	// 1 0 1 0  ==  10
	// 0 1 1 1  ==  7
	// -------
	// 0 0 1 0  ==  2
	
	printf("Bitwise 10 | 7 : %d\n", 10 | 7);
	// 1 0 1 0  ==  10
	// 0 1 1 1  ==  7
	// -------
	// 1 1 1 1  ==  15


	// XOR Truth Table
	// | X | Y | X ^ Y |
	// | 1 | 1 |   0   |
	// | 1 | 0 |   1   |
	// | 0 | 1 |   1   |
	// | 0 | 0 |   0   |

	printf("Bitwise 10 ^ 7 : %d\n", 10 ^ 7);
	// 1 0 1 0  ==  10
	// 0 1 1 1  ==  7
	// -------
	// 1 1 0 1  ==  13

	printf("Bitwise 20 ^ 14 : %d\n", 20 ^ 14);
	// 0 0 0 1 0 1 0 0  ==  20
	// 0 0 0 0 1 1 1 0  ==  14
	// ---------------  
	// 0 0 0 1 1 0 1 0  ==  26

	// Semua yang 0 jadi 1 dan 1 jadi 0
	printf("Bitwise ~8 : %d\n", ~8);

	// 00000000 00000000 00000000  0 0 0 0 1 0 0 0  ==  8
	// -------------------------------------------
	// 11111111 11111111 11111111  1 1 1 1 0 1 1 1  ==  -9

	// Rumus
	// (x + 1) * - 1 

	printf("Bitwise 8<<1 : %d\n", 8<<1);
	// 0000 1000  ==  8
	// -----------------
	// 0001 0000  ==  16
	
	printf("Bitwise 8<<2 : %d\n", 8<<2);
	// 0000 1000  ==  8
	// -----------------
	// 0010 0000  ==  32
	
	printf("Bitwise 8>>1 : %d\n", 8>>1);
	// 0000 1000  ==  8
	// -----------------
	// 0000 0100  ==  4
	
	printf("Bitwise 8>>2 : %d\n", 8>>2);
	// 0000 1000  ==  8
	// -----------------
	// 0000 0010  ==  2

	return 0;
}
