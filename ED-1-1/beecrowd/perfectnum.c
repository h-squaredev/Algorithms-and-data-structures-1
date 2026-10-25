#include <stdio.h>

int main() {
    int N; // Número de casos de teste
    int X; // O número a ser testado
    int i; // Contador para o loop de divisores
    int j; // Contador para o loop de casos de teste
    long long soma; // A soma dos divisores (usamos long long por segurança)

    // 1. Lê a quantidade de casos de teste
    scanf("%d", &N);

    // 2. Loop principal que executa N vezes
    for (j = 0; j < N; j++) {
        
        // 3. Lê o número X e reseta a soma
        scanf("%d", &X);
        soma = 0; // Zera a soma para cada novo número

        // 4. Loop interno: encontra e soma os divisores
        //    Só precisamos testar até a metade de X (X/2),
        //    pois não existe divisor (além dele mesmo) maior que a metade.
        for (i = 1; i <= X / 2; i++) {
            if (X % i == 0) {
                // Se 'i' é um divisor, adiciona à soma
                soma = soma + i;
            }
        }

        // 5. Verifica se a soma é igual ao número e imprime
        if (soma == X) {
            printf("%d eh perfeito\n", X);
        } else {
            printf("%d nao eh perfeito\n", X);
        }
    }

    return 0;
}