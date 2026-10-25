#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs()

// Função principal para o programa
int main() {
    int N; // Ordem da matriz (0 <= N <= 100)
    int M[100][100]; // Declaração da matriz (max N=100)
    int i, j;
    
    // Loop de leitura: continua enquanto o valor lido (N) não for 0
    while (scanf("%d", &N) == 1 && N != 0) {
        
        // 1. Construção da Matriz
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                // O valor é 1 + a diferença absoluta entre a linha e a coluna.
                // Usamos abs(i - j) para obter a distância até a diagonal principal.
                M[i][j] = abs(i - j) + 1;
            }
        }
        
        // 2. Impressão da Matriz (Formato Específico)
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                // Impressão: campo de tamanho 3, justificado à direita.
                // Use "%3d" para formatação.
                
                // Trata o primeiro elemento de cada linha (j=0)
                if (j == 0) {
                    // O primeiro elemento não tem espaço antes
                    printf("%3d", M[i][j]);
                } else {
                    // Os elementos seguintes são separados por um espaço
                    // O espaço é impresso ANTES da formatação de 3 caracteres.
                    printf(" %3d", M[i][j]);
                }
            }
            // Quebra de linha após o final de cada linha da matriz
            printf("\n");
        }
        
        // 3. Quebra de linha vazia após a impressão de CADA matriz
        printf("\n");
    }
    
    return 0;
}