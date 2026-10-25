#include <stdio.h>

int main() {
    int N; // Tamanho da matriz (N <= 101)
    int M[101][101]; // Matriz (máximo N=101)
    int i, j;
    int inicio_interno, fim_interno;
    
    // Loop de leitura: continua lendo N até que encontre o Fim do Arquivo (EOF)
    while (scanf("%d", &N) != EOF) {
        
        // --- 1. Definir os limites do Quadrado Interno (Valor '1') ---
        inicio_interno = N / 3;
        fim_interno = N - 1 - inicio_interno;
        
        // --- 2. Preenchimento da Matriz por Ordem de Prioridade Corrigida ---
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                
                // R1. Ponto Central (Prioridade Máxima): 4
                if (i == N / 2 && j == N / 2) {
                    M[i][j] = 4;
                } 
                // R2. Quadrado Interno (NOVA PRIORIDADE): 1
                // O quadrado interno deve ter prioridade sobre 2 e 3 onde se sobrepõe.
                else if (i >= inicio_interno && i <= fim_interno && 
                         j >= inicio_interno && j <= fim_interno) {
                    M[i][j] = 1;
                }
                // R3. Diagonal Secundária (NOVA PRIORIDADE): 3
                // Testa a diagonal secundária *APENAS* nas regiões onde 1 não cobre.
                else if (i + j == N - 1) {
                    M[i][j] = 3;
                }
                // R4. Diagonal Principal (NOVA PRIORIDADE): 2
                // Testa a diagonal principal *APENAS* nas regiões onde 1 não cobre.
                else if (i == j) {
                    M[i][j] = 2;
                }
                // R5. Parte Externa (Prioridade Mínima): 0
                else {
                    M[i][j] = 0;
                }
            }
        }
        
        // --- 3. Impressão da Matriz ---
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                printf("%d", M[i][j]);
            }
            printf("\n");
        }
        
        // --- 4. Linha em branco após cada caso de teste ---
        printf("\n");
    }
    
    return 0;
}