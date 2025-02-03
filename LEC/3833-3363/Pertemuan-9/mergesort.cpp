#include <stdio.h>

int print_array(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
    	if (i == size - 1)
        {
            printf("%d", arr[i]);
        }else{
            printf("%d, ", arr[i]);
        }
    }
}

void sort(int arr[], int left, int mid,int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArray[leftSize];
    int rightArray[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        leftArray[i] = arr[i + left];
    }
    
    for (int i = 0; i < leftSize; i++)
    {
        rightArray[i] = arr[i+mid+1];
    }
    
    int leftIndex = 0;
    int rightIndex = 0;
    int mergedIndex = left;

    while(leftIndex < leftSize && rightIndex < rightSize){
        int currentLeft = leftArray[leftIndex];
        int currentRight = rightArray[rightIndex];
        if (currentLeft < currentRight)
        {
            arr[mergedIndex] = currentLeft;
            leftIndex++;
        }else{
            arr[mergedIndex] = currentRight;
            rightIndex++;
        }
        mergedIndex++;        
    }
    
    while (rightIndex < rightSize)
    {
        int currentRight = rightArray[rightIndex];
        arr[mergedIndex] = currentRight;
        mergedIndex++;
        rightIndex++;
    }
    
    while (leftIndex < leftSize)
    {
        int currentLeft = leftArray[leftIndex];
        arr[mergedIndex] = currentLeft;
        mergedIndex++;
        leftIndex++;
    }

}

void merge_sort(int arr[], int left, int right){
    if(left >= right) return;

    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    sort(arr, left, mid, right);
}

int main(){
    int arr[] = {12,11,13,5,6,7};
    int size = sizeof(arr) / sizeof(int);
    printf("Before Sorting : [");
    print_array(arr, size);
    printf("]\n");

	merge_sort(arr, 0, size - 1);
	
    printf("After Sorting : [");
    print_array(arr, size);
    printf("]\n");
    return 0;
}
