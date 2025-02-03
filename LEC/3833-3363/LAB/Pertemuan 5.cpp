#include <stdio.h>

int main(){
    // [1] Pointer
    printf("[1] Pointer\n");
    
    int a = 10;
    int *ptrA = &a;

    printf("Value a = %d\n", a);
    printf("Value Pointer a = %d\n", ptrA);

    // & Ampersen Untuk Mengeprint Address
    printf("Address a = %d\n", &a);
    printf("Address Pointer a = %d\n", &ptrA);

    // *   Asterik Berfungsi untuk mengecek Address Lalu Mengecek Value
    //     Address -> Value 
    // a = 6487580 -> 10 
    
    printf("Asterik Pointer a = %d\n", *ptrA);
    
    // [2] Array
    printf("\n[2] Array 1 Dimensi\n");
    int arr[3] = {2,4,6};

    printf("%d\n", arr[2]);
    
	// for(int i=0; i<3; i++){
    //     printf("%d\n", arr[i]);
    // }

    printf("\n[3] Array 2 Dimensi\n");
    int arr2D[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d\n", arr2D[i][j]);
        }
    }
	
	
    // printf("%d", arr2D[0][0]);

	int array22[3][4] = {{2,2,2,2}, {2,2,2,2}, {2,2,2,2}};

    
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            printf("%d", array22[i][j]);
        }
        printf("\n");
    }
    
	return 0;
}
