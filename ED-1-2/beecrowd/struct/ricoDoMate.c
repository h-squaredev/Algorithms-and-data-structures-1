#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar os dados de cada peça de carne
typedef struct {
    char nome[21];
    int validade;
} Carne;

// Função de comparação utilizada pela função qsort
int comparar(const void *a, const void *b) {
    Carne *carneA = (Carne *)a;
    Carne *carneB = (Carne *)b;
    // Ordena de forma crescente pela data de validade
    return carneA->validade - carneB->validade;
}

int main() {
    int n;

    // O loop continua lendo até encontrar o Fim de Arquivo (EOF)
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            printf("\n");
            continue;
        }

        Carne carnes[15];

        // Leitura dos nomes e validades
        for (int i = 0; i < n; i++) {
            scanf("%s %d", carnes[i].nome, &carnes[i].validade);
        }

        // Ordenação do array usando a função qsort
        qsort(carnes, n, sizeof(Carne), comparar);

        // Impressão dos resultados separados por espaço
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%s", carnes[i].nome);
        }
        printf("\n"); // Quebra de linha ao final de cada caso de teste
    }

    return 0;
}