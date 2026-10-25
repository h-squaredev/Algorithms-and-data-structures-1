#include <stdio.h>

#define N 12

int A[N][N] = {
    {   0,   7, 218, 503, 515, 219, 241, 417, 352, 239, 810, 448 },
    {   7,   0, 222, 496, 520, 212, 234, 410, 345, 243, 803, 441 },
    { 218, 222,   0, 719, 407, 435, 457, 633, 568, 130,1026, 665 },
    { 503, 496, 719,   0,1016, 521, 511,  89, 152, 739, 315, 650 },
    { 515, 520, 407,1016,   0, 732, 754, 930, 865, 278,1323, 900 },
    { 219, 212, 435, 521, 732,   0, 230, 607, 543, 455,1001, 308 },
    { 241, 234, 457, 511, 754, 230,   0, 425, 360, 480, 818, 493 },
    { 417, 410, 633,  89, 930, 607, 425,   0,  66, 656, 396, 520 },
    { 352, 345, 568, 152, 865, 543, 360,  66,   0, 588, 459, 450 },
    { 239, 243, 130, 739, 278, 455, 480, 656, 588,   0,1046, 685 },
    { 810, 803,1026, 315,1323,1001, 818, 396, 459,1046,   0, 700 },
    { 448, 441, 665, 650, 900, 308, 493, 520, 450, 685, 700,   0 }
};

const char *nomes[N] = {
    "Cuiaba", "Varzea Grande", "Rondonopolis", "Sinop",
    "Barra do Garcas", "Caceres", "Tangara da Serra", "Sorriso",
    "Lucas do Rio Verde", "Primavera do Leste", "Alta Floresta",
    "Pontes e Lacerda"
};

/* Preenche dist[i] com a distancia (em arestas) de c ate i. */
void distancias(int A[][N], int c, int dist[N]) {
    int fila[N], ini = 0, fim = 0;

    for (int i = 0; i < N; i++)
        dist[i] = -1;               /* -1 = nao visitada */

    dist[c] = 0;
    fila[fim++] = c;                /* enfileira */

    while (ini < fim) {
        int u = fila[ini++];        /* desenfileira */
        for (int v = 0; v < N; v++) {
            if (A[u][v] != 0 && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                fila[fim++] = v;
            }
        }
    }
}

int main(void) {
    int dist[N];
    int c = 0;                      /* Cuiaba */

    distancias(A, c, dist);

    printf("Distancias a partir de %s:\n", nomes[c]);
    for (int i = 0; i < N; i++)
        printf("  %-20s : %d\n", nomes[i], dist[i]);

    return 0;
}