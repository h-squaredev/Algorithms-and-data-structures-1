#include <stdio.h>
#include <stdlib.h>

int main () {
    int num;
   
    printf("Informe seu numero: ");
    scanf ("%d", &num);

    if (num > 20){
    printf("Seu numero %d eh maior que 20! Bom trabalho!\n", num);

    } else {
    printf("Seu numero %d nao eh maior que 20! Tente novamente!\n", num);
    }




return 1;
}