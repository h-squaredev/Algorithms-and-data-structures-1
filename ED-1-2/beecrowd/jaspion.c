#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar cada par do dicionário
typedef struct {
    char jp[100];
    char pt[100];
} Dict;

// Função de comparação para o qsort (ordena as palavras em japonês alfabeticamente)
int comparar(const void *a, const void *b) {
    Dict *d1 = (Dict *)a;
    Dict *d2 = (Dict *)b;
    return strcmp(d1->jp, d2->jp);
}

// Função de comparação para o bsearch (busca a palavra da música no dicionário)
int buscar(const void *key, const void *element) {
    const char *palavra = (const char *)key;
    Dict *d = (Dict *)element;
    return strcmp(palavra, d->jp);
}

int main() {
    char linha[100];
    int T;

    // Usamos fgets no lugar de scanf para evitar que 'lixos' de quebra de linha (\n) 
    // buguem as próximas leituras.
    if (fgets(linha, sizeof(linha), stdin) == NULL) return 0;
    sscanf(linha, "%d", &T);

    while (T--) {
        int M, N;
        if (fgets(linha, sizeof(linha), stdin) == NULL) break;
        sscanf(linha, "%d %d", &M, &N);

        // Alocação dinâmica: Cria o dicionário direto na memória Heap.
        // Essencial, já que M pode chegar a 1.000.000 e estouraria a pilha do C (Stack Overflow).
        Dict *dicionario = (Dict *)malloc(M * sizeof(Dict));

        // Leitura do dicionário
        for (int i = 0; i < M; i++) {
            fgets(dicionario[i].jp, sizeof(dicionario[i].jp), stdin);
            dicionario[i].jp[strcspn(dicionario[i].jp, "\r\n")] = '\0'; // Remove o \n do final

            fgets(dicionario[i].pt, sizeof(dicionario[i].pt), stdin);
            dicionario[i].pt[strcspn(dicionario[i].pt, "\r\n")] = '\0';
        }

        // Ordena o dicionário pelo japonês (requisito para a busca binária funcionar)
        qsort(dicionario, M, sizeof(Dict), comparar);

        // Leitura e tradução das linhas da música
        for (int i = 0; i < N; i++) {
            fgets(linha, sizeof(linha), stdin);
            linha[strcspn(linha, "\r\n")] = '\0';

            // strtok quebra a frase inteira em palavras separadas pelo espaço " "
            char *palavra = strtok(linha, " ");
            int primeira_palavra = 1;

            // Se a linha for vazia, o strtok retorna NULL, o while não roda 
            // e o programa imprime apenas o \n no fim do laço (o que é o correto!)
            while (palavra != NULL) {
                // Adiciona espaço antes das palavras (exceto na primeira)
                if (!primeira_palavra) {
                    printf(" ");
                }

                // Dispara a busca binária na velocidade da luz (O(log M))
                Dict *resultado = bsearch(palavra, dicionario, M, sizeof(Dict), buscar);
                
                if (resultado != NULL) {
                    printf("%s", resultado->pt); // Imprime a tradução
                } else {
                    printf("%s", palavra);       // Imprime a original se não existir no dicionário
                }

                primeira_palavra = 0;
                palavra = strtok(NULL, " "); // Pega a próxima palavra da frase
            }
            printf("\n");
        }
        
        printf("\n"); // O problema exige uma linha em branco após cada instância
        free(dicionario); // Libera a memória antes da próxima rodada do while
    }

    return 0;
}