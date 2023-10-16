#include <stdio.h>
#include <string.h>

int main(){
    // printf("%d\n", 'a');
    // printf("%d\n", 'A');

    int diff = 'a' - 'A';

    char string[10001];
    scanf("%[^\n]", &string);

    int n = strlen(string);
    int mid = n / 2;

    bool isPalindrome = true;
    for(int i=0; i < mid; i++){
        char left = string[i];
        char right = string[n-i-1];
        
        if (left >= 'A' && left <= 'Z'){
            left += diff;
        }

        if (right >= 'A' && right <= 'Z'){
            right += diff;
        }

        if(left != right){
            isPalindrome = false;
            break;
        }
    }

    if(isPalindrome)printf("%s is Palindrome", string);
    else printf("%s is not Palindrome", string);
    return 0;
}
