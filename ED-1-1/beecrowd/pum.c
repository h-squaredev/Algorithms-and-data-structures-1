#include <stdio.h>

int main() {
    int N;
    
    //Lê a quantidade de linhas
    printf("Digite um numero inteiro N: ");
    scanf("%d", &N);

    //Cria uma variável para "lembrar" o número inicial de cada linha
    int contador = 1;

    //Cria um loop que vai de 0 até N-1 (executando N vezes)
    for (int i = 0; i < N; i++) {
        
        // Imprime a linha com os 3 números e "PUM"
        //    Na primeira volta: 1, 1+1, 1+2
        //    Na segunda volta: 5, 5+1, 5+2
        printf("%d %d %d PUM\n", contador, contador + 1, contador + 2);
        
        // Atualiza o contador para a próxima linha
        //    (Pulamos 3 números + o "PUM", então somamos 4)
        contador = contador + 4;
    }

    return 0;
}