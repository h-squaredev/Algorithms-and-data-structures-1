#include <stdio.h>
 
int main() {
 
    int N;

    printf("Digite um numero inteiro: ");
    scanf("%d", &N);

    if (N < 0 || N > 1000){
        printf("Numero invalido! Digite um numero inteiro entre 0 e 1000: ");
        scanf("%d", &N);
        return 0;

    }else{
        for (int i = 1; i <= 10; i++){
            printf("%d x %d = %d\n", i, N, i * N);
        }

    }

    return 0;
}