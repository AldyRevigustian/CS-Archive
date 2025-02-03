#include <stdio.h>

int linearSearch(int array[], int size, int n){
    for (int i = 0; i < size; i++)
    {
        if (array[i] == n) return i;
    }
    return -1;
}

int binarySearch(int array[], int size, int n){
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) /2;
        if (array[mid] > n)
        {
            right = mid - 1;
        }else if (array[mid] < n)
        {
            left = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int interpolationSearch(int array[], int size, int n){
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        double ls = ((double)right - left) * (n - array[left]) / (array[right] - array[left]);

        int probe = left + ls;

        if (array[probe] > n)
        {
            right = probe - 1;
        }else if(array[probe] < n){
            left = probe - 1;
        }else{
            return probe;
        }
    }
    return -1;
}

int problem(int array[], int size, int target){
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if(array[mid] == target) return mid;

        if (array[left] <= array[mid])
        {
            if (array[left] <= target && target <= array[mid])
            {
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }else{
            if (target > array[mid] && target <= array[right])
            {
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    int larray[] = {1, 2, 3, 4, 10};
    int sizeL = sizeof(larray) / sizeof(int);
    int nL = 10;
    
    int barray[] = {1, 2, 3, 4, 10};
    int sizeB = sizeof(barray) / sizeof(int);
    int nB = 10;

    // printf("%d", linearSearch(larray, sizeL, nL));
    // printf("%d", binarySearch(barray, sizeB, nB));
    // printf("%d", interpolationSearch(barray, sizeB, nB));

    int arr1[] = {10,11,12,13,14,15};
    int size1 = sizeof(arr1) / sizeof(int);
    
    int arr2[] = {2,3,4,5,6,7,8};
    int size2 = sizeof(arr2) / sizeof(int);

    const int size3 = (sizeof(arr1) / sizeof(int)) + (sizeof(arr2) / sizeof(int)); 
    int arr3[size3];

    for (int i = 0; i < size1; i++)
    {
        arr3[i] = arr1[i];
    }

    int i, j;

    for ( i = 0, j = size1; j < size3 && i< size2; i++, j++){
        arr3[j] = arr2[i];
    }

    printf("%d", problem(arr3, size3, 13));

    

    return 0;
}
