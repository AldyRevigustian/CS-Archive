#include<stdio.h>
#include<string.h>

//Basic Sorting
//Bubble sort
//Selection sort
//Insertion sort

//swap
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//bubble sort
void bubbleSort(int arr[], int size){
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
	
}

//Selection sort
void selectionSort(int arr[], int size){
	int min;
	for(int i=0;i<size;i++){
		min = i;
		for(int j=0;j<size;j++){
			if(arr[min] > arr[j]){
				min = j;
			}
		}
		swap(&arr[min], &arr[i]);
	}
}

//Insertion sort
void insertionSort(int arr[], int size){
	for(int i=0;i<size;i++){
		int flag = arr[i];
		int j = i-1;
		
		while(j >= 0 && arr[j] > flag){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = flag;
	}
}



//print
void printArray(int arr[], int size){
	
	for(int i=0;i<size;i++){
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}



int main(){
	
	//Bubble Sort
	
	int arr[] = {21, 9, 18, 25, 2};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Sebelum sorting : \n");
	printArray(arr, size);
	
	insertionSort(arr, size);
	printf("Setelah sorting : \n");
	printArray(arr, size);
	
	
	
	//int -> 4 bit
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(arr[0]));
//	printf("%d", sizeof(arr)/sizeof(arr[0]));
	
	
	return 0;
}
