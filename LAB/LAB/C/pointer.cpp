#include <stdio.h>

int main(){
    int a = 2;
    int* p_a = &a;
	int** p_p_a = &p_a;
	
    printf("%d\n", *p_a);
    printf("%p\n", p_a);
    
    printf("%d\n", **p_p_a);
    printf("%p\n", p_p_a);
    return 0;
}
