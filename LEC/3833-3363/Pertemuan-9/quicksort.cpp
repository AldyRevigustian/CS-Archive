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

int partition(int arr[], int left, int right){
    int pivot = arr[right];

    int i = left - 1;
    
    for (int n = left; n < right; n++)
    {
        if (arr[n] < pivot)
        {
            i++;
            int temp = arr[n];
            arr[n] = arr[i];
            arr[i] = temp;
        }
        
    }
    i++;
     int temp = arr[right];
    arr[right] = arr[i];
    arr[i] = temp;

    return i;
}

void quicksort(int arr[], int left, int right){
    if(left >= right) return;
    int p = partition(arr, left, right);

    quicksort(arr, left, p - 1);
    quicksort(arr, p+1, right);
}

int main(){
    int arr[] = {12,11,13,5,6,7};
    int size = sizeof(arr) / sizeof(int);
    printf("Before Sorting : [");
    print_array(arr, size);
    printf("]\n");

    quicksort(arr, 0, size-1);

    printf("After Sorting : [");
    print_array(arr, size);
    printf("]\n");
    return 0;
}
