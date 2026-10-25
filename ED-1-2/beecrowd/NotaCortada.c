/*
Regras:
1- Se um dos pedaços da nota possuir mais da metade da area == ele valer 100 reais
e o outro pedaco nao vale nada

2- a area da nota é igual para cada pedaco == sem valor para os dois

-------
saida 1 se Felix ganhou (Lado esquerdo maior)
saida 2 se Marzia ganho (Lado direito maior)
saida 0 se o valor da nota se perdeu
*/

#include <stdio.h>

void calculo(int b, int t) { 
    if (b + t > 160) {
        printf("1\n");
    } else if (b + t < 160) {
        printf("2\n");
    } else {
        printf("0\n");
    }
}

int main() {
    int B, T;

    //entrada do tamanho inferior (B) e superior (T) do corte
    scanf("%d", &B);
    scanf("%d", &T);

    calculo(B, T);
    
    return 0;
}