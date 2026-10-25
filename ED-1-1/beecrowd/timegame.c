#include <stdio.h>

int main() {

    int inicio, final, resultado, h1, m1, h2, m2;

    printf("Digite a hora e minuto de inicio do jogo: ");
    scanf("%d %d", &h1, &m1);
    printf("Digite a hora e minuto de termino do jogo: ");
    scanf("%d %d", &h2, &m2);

    inicio = h1 * 60 + m1;
    final = h2 * 60 + m2;
    resultado = final - inicio;

    if (resultado <= 0) {
        resultado += 24 * 60;
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", resultado / 60, resultado % 60);


    return 0;
}