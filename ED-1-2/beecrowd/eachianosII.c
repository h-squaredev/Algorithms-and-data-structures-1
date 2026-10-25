#include <stdio.h>
#include <string.h>

int main() {
    int q;
    
    // Lê a quantidade de instâncias. Retorna 0 se falhar (boa prática pro EOF).
    if (scanf("%d", &q) != 1) return 0;
    
    // Limpa o caractere de quebra de linha '\n' deixado pelo scanf
    // para que o fgets não leia uma linha em branco por engano.
    getchar(); 

    while (q--) {
        char texto[150];
        char palavra[150];

        // Lê o texto e remove o terminador de quebra de linha (\n ou \r\n)
        fgets(texto, sizeof(texto), stdin);
        texto[strcspn(texto, "\r\n")] = '\0';

        // Lê a palavra de busca e também remove a quebra de linha
        fgets(palavra, sizeof(palavra), stdin);
        palavra[strcspn(palavra, "\r\n")] = '\0';

        int len_palavra = strlen(palavra);
        int encontrou = 0;
        int primeiro_print = 1; // Controle para formatação de espaços

        // Ponteiro auxiliar para varrer a string
        char *ptr = texto;

        // O strstr procura a próxima ocorrência da palavra na string.
        // Ele retorna NULL quando não encontrar mais nada.
        while ((ptr = strstr(ptr, palavra)) != NULL) {
            
            // Verifica a Fronteira Esquerda:
            // É o começo do texto? Ou tem um espaço antes?
            int inicio_valido = (ptr == texto) || (*(ptr - 1) == ' ');

            // Verifica a Fronteira Direita:
            // É o fim do texto (\0)? Ou tem um espaço depois?
            int fim_valido = (*(ptr + len_palavra) == ' ') || (*(ptr + len_palavra) == '\0');

            // Se for uma palavra exata (passou nas duas fronteiras)
            if (inicio_valido && fim_valido) {
                // Se não for o primeiro número a ser impresso na linha, coloca um espaço antes
                if (!primeiro_print) {
                    printf(" ");
                }
                
                // O índice exato é a diferença entre o endereço do ponteiro atual e o início do texto
                printf("%d", (int)(ptr - texto));
                
                encontrou = 1;
                primeiro_print = 0;
            }

            // Avança o ponteiro para continuar a busca a partir do fim da palavra atual
            ptr += len_palavra;
        }

        // Se a flag continuar zerada, a palavra exata não existe no texto
        if (!encontrou) {
            printf("-1");
        }
        
        // Quebra a linha para o próximo caso de teste
        printf("\n");
    }

    return 0;
}