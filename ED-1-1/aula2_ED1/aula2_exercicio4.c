#include <stdio.h>
#include <stdlib.h>

int main () {
    int num1, num2, adicao;
   
    printf("Informe seu primeiro numero: ");
    scanf ("%d", &num1);
    printf("Informe seu segundo numero: ");
    scanf ("%d", &num2);

    adicao = num1 + num2;
    
     if (adicao > 10){
    printf("A adicao entre os dois numeros %d e %d eh %d, ou seja, maior que 10! Bom trabalho!\n", num1, num2, adicao);

    } else {
    printf("A adicao dois dois numeros %d e %d nao eh maior que 10! Tente novamente!\n", num1, num2);
    }


return 1;
}