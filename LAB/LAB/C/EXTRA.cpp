#include <stdio.h>

int main(){
    int width, length;
    char map[length][width];
    scanf("%d %d", &width, &length);
    getchar();

    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            if(i == 0 || i == length - 1){
                map[i][j] = '*';
                printf("*");

            }else if(j == 0 || j == length -1){
                map[i][j] = '*';
                
                printf("*");
			}else{
                printf(" ");
            }   
        }
        printf("\n");
    }
    return 0;
}
