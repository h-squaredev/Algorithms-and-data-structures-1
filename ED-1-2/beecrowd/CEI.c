#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para o qsort ordenar inteiros
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    // O problema diz que N vai no máximo até 1000, 
    // então um array estático resolve perfeitamente.
    int minutos[1005]; 

    // Lê os casos de teste até o Fim do Arquivo (EOF)
    while (scanf("%d", &n) != EOF) {
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &minutos[i]);
        }

        // Ordena os tempos em ordem crescente
        qsort(minutos, n, sizeof(int), comparar);

        // A quantidade de convidados é exatamente a metade dos registros
        int max_convidados = n / 2;

        // O tempo juntos é a diferença entre a primeira saída e a última entrada.
        // Como o array em C começa em 0, o índice (n / 2) aponta para a primeira saída
        // e o índice (n / 2) - 1 aponta para a última entrada.
        int tempo_juntos = minutos[n / 2] - minutos[(n / 2) - 1];

        printf("%d %d\n", max_convidados, tempo_juntos);
    }

    return 0;
}