#include <stdio.h>
#include <string.h>

void desenhar_relogio(int h, int m) {
    char relogio[15][50];
    
    strcpy(relogio[0],  " ____________________________________________");
    strcpy(relogio[1],  "|                                            |");
    strcpy(relogio[2],  "|    ____________________________________    |_");
    strcpy(relogio[3],  "|   |                                    |   |_)");
    strcpy(relogio[4],  "|   |   8         4         2         1  |   |");
    strcpy(relogio[5],  "|   |                                    |   |");
    strcpy(relogio[6],  "|   |                                    |   |");
    strcpy(relogio[7],  "|   |                                    |   |");
    strcpy(relogio[8],  "|   |                                    |   |");
    strcpy(relogio[9],  "|   |                                    |   |");
    strcpy(relogio[10], "|   |                                    |   |");
    strcpy(relogio[11], "|   |   32    16    8     4     2     1  |   |_");
    strcpy(relogio[12], "|   |____________________________________|   |_)");
    strcpy(relogio[13], "|                                            |");
    strcpy(relogio[14], "|____________________________________________|");

    // Operação binária para acender as Horas
    if (h & 8) relogio[6][8]  = 'o';
    if (h & 4) relogio[6][18] = 'o';
    if (h & 2) relogio[6][28] = 'o';
    if (h & 1) relogio[6][38] = 'o';

    // Operação binária para acender os Minutos
    if (m & 32) relogio[9][8]  = 'o';
    if (m & 16) relogio[9][14] = 'o';
    if (m & 8)  relogio[9][20] = 'o';
    if (m & 4)  relogio[9][26] = 'o';
    if (m & 2)  relogio[9][32] = 'o';
    if (m & 1)  relogio[9][38] = 'o';

    // Imprime o relógio montado
    for (int i = 0; i < 15; i++) {
        printf("%s\n", relogio[i]);
    }
}

int main() {
    int h, m;
    int primeiro = 1;
    
    while (scanf("%d:%d", &h, &m) == 2) {
        // Imprime a linha em branco antes dos desenhos seguintes, 
        // evitando o excesso de quebras de linha no final do arquivo.
        if (!primeiro) {
            printf("\n");
        }
        primeiro = 0;
        
        desenhar_relogio(h, m);
    }
    
    return 0;
}