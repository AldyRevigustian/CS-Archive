#include <stdio.h>

// Global Variable
int angka = 20;

void greeting(char name[]){
    printf("Hello %s\n", name);
}

int add(int a, int b){
    return a+b;
}

int multiply(int a, int b){
    return a*b;
}

void swapByValue(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    printf("After swap by value : %d %d\n", a, b);
}

void swapByReference(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("After swap By Reference : %d %d\n", *a, *b);
}

int fibo(int n){
    if(n <= 1){
        return n;
    }
    return fibo(n - 1) + fibo(n -2);
    // n = 2
    // return fibo(2 - 1) + fibo(2 - 2);
    // return fibo(1) + fibo(0);
    // return 1 + 0;
    
    // n = 3
    // return fibo(3 - 1) + fibo(3 - 2);
    // return fibo(2) + fibo(1);

    // n = 4;
    // return fibo(4 - 1) + fibo(4 - 2);
    // return fibo(3) + fibo(2);
    // return fibo(3) + fibo(2);
}

int faktorial(int n){
    if (n == 0)
    {
        return 1;
    }
    //printf("%d", n);
    // return faktorial(n - 1);
    return n * faktorial(n - 1);
    // 5 4 3 2 1
}
int main(){
    // Function
    // int a,b;
    // greeting("Aldy");
    // printf("%d\n", add(1, 1));
    
    // scanf("%d %d\n", &a, &b);

    // printf("Add %d\n", add(a, b));
    // printf("Multiply %d\n", multiply(a, b));
    
    
    // // Variable
    // int angka = 10;
    // printf("%d", angka);

    // Passing by Value & Passing by Reference
    // Value ya value Reference ya address nya

    // Swap
    // int a = 20;
    // int b = 10;

    // printf("A = %d, B = %d\n", a, b);
    // swapByValue(a, b);
    // printf("A = %d, B = %d\n", a, b);
    // swapByReference(&a, &b);
    // printf("A = %d, B = %d\n", a, b);

    // printf("%d", fibo(10));

    // for(int i = 0; i<=10; i++){
    //     printf("%d\n", fibo(i));
    // }
    
    // for(int i = 0; i<=10; i++){
    //     printf("%d\n", fak(i));
    // }

    // faktorial(5);
    printf("%d", faktorial(5));

    return 0;
}
