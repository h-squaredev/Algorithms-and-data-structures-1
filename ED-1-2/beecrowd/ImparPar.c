#include <stdio.h>
 
int main() {
    //Declacao de variavel e scan 
    int N, X;
    if (scanf("%d", &N) != 1) return 0;

    for(int i = 0; i < N; i++){
        scanf("%d", &X);
        //verificao e impressao
        if(X == 0){
            printf("NULL\n");
        } else if (X % 2 == 0){
            if(X > 0){
                printf("EVEN POSITIVE\n");
            }else{
                printf("EVEN NEGATIVE\n");
            }
        }else{
            if (X > 0){
                printf("ODD POSITIVE\n");
            }else{
                printf("ODD NEGATIVE\n");
            }
        }
    }

    return 0;
}