#include <stdio.h>

// int binary_search(int a[], int low, int high, int target) {
//     if (high < low)
//         return -1;
//     int middle = (low + high)/2;
//     if (target < a[middle])
//         return binary_search(a, low, middle-1, target);
//     else if (target > a[middle])
//         return binary_search(a, middle+1, high, target);
//     else if (target == a[middle])
//         return middle+1;
// }

int binary_search(int nums[],int low, int high, int target) {
    int l = low, r = high;
    while (l < r) {
        int m = (l + r) / 2;
        if (nums[m] < target) l = m + 1;
        else r = m;
    }
    return (nums[l]==target)?l+1:-1;
}

int main(){
    int n,t;
    scanf("%d %d",&n,&t);getchar();
    int num[n];
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);getchar();
    }
    for(int i=0;i<t;i++){
        int temp;
        scanf("%d",&temp);getchar();
        printf("%d\n",binary_search(num,0,n-1,temp));
    }
}