#include <stdio.h>
#include <stdlib.h>

int main () {
    int b, n, resultado;
   
    printf("Informe o o valor da base ( maior que 1 ) para calcular a potencia: \t");
    scanf ("%d", &b);
    if (b < 1) {
        printf("Seu valor eh menor que 1 :( \n");
        return 1;
    
    }else{
    printf("Informe o valor do expoente (maior ou igual a 2) para calcular a potencia: \t");
    scanf ("%d", &n);

    if (n < 2) {
        printf("\n Seu valor eh menor que 2 :(");
        return 1;

    }else{
        resultado = 1;
        for (int i = 1; i <= n; i++) {
            resultado = resultado * b;
        }
        printf("\n O valor de %d^%d eh: %d \n", b, n, resultado);
        
        }
    
    }
    return 1;
}
