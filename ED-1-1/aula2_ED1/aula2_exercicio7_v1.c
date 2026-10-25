#include <stdio.h>
#include <stdlib.h>

int main () {
    int num;
    printf("Agora iremos imprimir todos os numeros multiplos de 5 de 1 ate 500!\n");
    for (num = 1; num <= 500; num++) {
        if (num % 5 == 0) {
            printf("%d\n", num);
        }
    }
return 1;
}