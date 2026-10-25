#include <stdio.h>
 
int main() {
 
    int N;

    printf("Digite um numero par inteiro: ");
    scanf("%d", &N);

    if (N % 2 != 0) {
        printf("Numero invalido! Digite um numero inteiro par.\n");
        return 0;
    }else if (N < 0 || N > 10000){
        printf("Numero invalido! Digite um numero inteiro entre 0 e 10000: ");
        scanf("%d", &N);

    }else{
        for (int i = 2; i <= N; i += 2){
            if (i % 2 == 0){
                printf("%d^2 = %d\n", i, i * i);
            }

        }
    }

    return 0;
}