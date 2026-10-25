#include <stdio.h>
#include <stdlib.h>

float main () {
    float valores, media, entrada;
    int contador;

    valores = 0;
    contador = 0;
    while (1) {
        printf("Insira um valor positivo (ou um valor negativo para encerrar): ");
        scanf ("%f", &entrada);
        if (entrada < 0) {
            break;
        }
        valores += entrada;
        contador++;
    }
    if (contador == 0) {
        printf("Nenhum valor positivo foi inserido!\n");
    } else {
        media = valores / contador;
        printf("A media dos valores inseridos eh: %.2f\n", media);
    }
    return 1;
}