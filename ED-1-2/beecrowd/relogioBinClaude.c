#include <stdio.h>

void converter(int valor, char *vet, int tamanho) {
    int i;
    for (i = tamanho - 1; i >= 0; i--) {
        vet[i] = valor % 2;
        valor /= 2;
    }
}

void imprimir(char *hora, char *minuto) {
    printf(" ____________________________________________\n");
    printf("|                                            |\n");
    printf("|    ____________________________________    |_\n");
    printf("|   |                                    |   |_)\n");
    printf("|   |   8         4         2         1  |   |\n");
    printf("|   |                                    |   |\n");

    printf("|   |   ");
    printf(hora[0] ? "o         " : "          ");
    printf(hora[1] ? "o         " : "          ");
    printf(hora[2] ? "o         " : "          ");
    printf(hora[3] ? "o  "        : "   ");
    printf("|   |\n");

    printf("|   |                                    |   |\n");
    printf("|   |                                    |   |\n");

    printf("|   |   ");
    printf(minuto[0] ? "o     " : "      ");
    printf(minuto[1] ? "o     " : "      ");
    printf(minuto[2] ? "o     " : "      ");
    printf(minuto[3] ? "o     " : "      ");
    printf(minuto[4] ? "o     " : "      ");
    printf(minuto[5] ? "o  "    : "   ");
    printf("|   |\n");

    printf("|   |                                    |   |\n");
    printf("|   |   32    16    8     4     2     1  |   |_\n");
    printf("|   |____________________________________|   |_)\n");
    printf("|                                            |\n");
    printf("|____________________________________________|\n\n");
}

int main(void) {
    int h, m;
    char hora[4], minuto[6];

    while (scanf("%d:%d", &h, &m) != EOF) {
        converter(h, hora, 4);
        converter(m, minuto, 6);
        imprimir(hora, minuto);
    }

    return 0;
}