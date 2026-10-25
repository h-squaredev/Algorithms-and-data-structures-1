#include <stdio.h>

// O problema pede um "inteiro de 64 bits sem sinal". 
// Isso é o `unsigned long long int` em C.
typedef unsigned long long int ulli;

// Vamos pré-calcular os termos até Fib(60)
// Um array de tamanho 61 para armazenar Fib(0) a Fib(60)
ulli fib_cache[61];

void pre_calcula_fibonacci() {
    fib_cache[0] = 0; // Fib(0) = 0
    fib_cache[1] = 1; // Fib(1) = 1

    for (int i = 2; i <= 60; i++) {
        // Fib(i) = Fib(i-1) + Fib(i-2)
        fib_cache[i] = fib_cache[i-1] + fib_cache[i-2];
    }
}

int main() {
    int T; // Número de casos de teste
    int N; // O índice N do termo Fib(N)

    // 1. Pré-calcular o vetor de Fibonacci
    pre_calcula_fibonacci();

    // 2. Ler o número de casos de teste (T)
    if (scanf("%d", &T) != 1) return 0;

    // 3. Loop para cada caso de teste
    for (int i = 0; i < T; i++) {
        // 4. Ler o índice N (0 <= N <= 60)
        if (scanf("%d", &N) != 1) continue;

        // 5. Imprimir a saída no formato exigido
        // O termo (X) é pego diretamente do vetor pré-calculado.
        printf("Fib(%d) = %llu\n", N, fib_cache[N]);
    }

    return 0;
}