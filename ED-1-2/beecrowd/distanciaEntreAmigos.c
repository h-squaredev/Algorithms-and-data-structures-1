#include <stdio.h>

// Função auxiliar para retornar o maior entre dois números long long
long long max(long long a, long long b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    
    // Lê a quantidade de prédios
    if (scanf("%d", &n) != 1) return 0;

    long long max_dist = 0;
    long long max_valor_i = 0; 
    
    // Lê o primeiro prédio separadamente para inicializar o valor de 'i'
    long long a_0;
    scanf("%lld", &a_0);
    
    // Para o primeiro prédio (índice 0), a fórmula (A_i - i) é apenas (a_0 - 0)
    max_valor_i = a_0;

    // Começa a olhar a partir do segundo prédio (índice 1 até n-1)
    for (int j = 1; j < n; j++) {
        long long a_j;
        scanf("%lld", &a_j);
        
        // A distância máxima usando o prédio 'j' como destino e o melhor 'i' do passado
        long long distancia_atual = max_valor_i + a_j + j;
        
        // Atualiza a distância máxima global se a atual for maior
        max_dist = max(max_dist, distancia_atual);
        
        // Atualiza o melhor (A_i - i) para os próximos prédios usarem
        max_valor_i = max(max_valor_i, a_j - j);
    }

    // Imprime a resposta final
    printf("%lld\n", max_dist);

    return 0;
}