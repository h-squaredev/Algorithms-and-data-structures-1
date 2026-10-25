#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definindo a estrutura (registro)
typedef struct Registro {
    char pais[100];
    int confirmados;
    int mortes;
    int recuperados;
    struct Registro* prox; //ponteiro que aponta para o prox pais na lista
} Registro;

//funcao para criar um novo noh da lista
Registro* CriarRegistro (char* pais, int confirmados, int mortes, int recuperados) {
    Registro* novo = (Registro*)malloc(sizeof(Registro));
    strcpy(novo->pais, pais);
    novo->confirmados = confirmados;
    novo->mortes = mortes;
    novo->recuperados = recuperados;
    novo->prox = NULL;
}

//funcao para ler o CSV e retornar o inicio da lista
Registro* CarregarDados(){
    FILE* arquivo = fopen("dataBase/country_wise_latest.csv", "r");
    if (arquivo == NULL) {
        printf("ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO!\n");
        return NULL;
    }
    Registro* cabeca = NULL; //inicializa a cabeca da lista como NULL
    char linha[512];

    //le a primeira linha e nao faz nada com ela (CABECALHO)
    fgets(linha, sizeof(linha), arquivo);

    //Le o arquivo linha por linha a partir da segunda linha
    while (fgets(linha, sizeof(linha), arquivo)) {
       char* pais = strtok(linha, ",");
        char* confirmados_str = strtok(NULL, ",");
        char* mortes_str = strtok(NULL, ",");
        char* recuperados_str = strtok(NULL, ",");

        // Converte os textos numericos para inteiros (atoi)
        if (pais && confirmados_str && mortes_str && recuperados_str) {
            int conf = atoi(confirmados_str);
            int mort = atoi(mortes_str);
            int rec = atoi(recuperados_str);

            // Cria o registro e insere no início da lista (mais rápido)
            Registro* novo = CriarRegistro(pais, conf, mort, rec);
            novo->prox = cabeca;
            cabeca = novo;
        }
    }

    fclose(arquivo);
    return cabeca; // Retorna a lista pronta
}

// Função principal para organizar o Heap (Sobe o elemento)
void subir(Registro* heap[], int i, int tipo) {
    while (i > 0) {
        int pai = (i - 1) / 2;
        int val_atual, val_pai;

        // Define qual valor comparar baseado no menu
        if (tipo == 1) { val_atual = heap[i]->confirmados; val_pai = heap[pai]->confirmados; }
        else if (tipo == 2) { val_atual = heap[i]->mortes; val_pai = heap[pai]->mortes; }
        else { val_atual = heap[i]->recuperados; val_pai = heap[pai]->recuperados; }

        if (val_atual > val_pai) {
            Registro* temp = heap[i];
            heap[i] = heap[pai];
            heap[pai] = temp;
            i = pai;
        } else break;
    }
}

// A função main que junta tudo
int main() {
    Registro* lista = CarregarDados(); // Parte 1 
    if (!lista) return 1;

    int opcao, qtd;
    do {
        printf("\n1-Casos  2-Mortes  3-Recuperados  0-Sair: "); // Parte 5 
        scanf("%d", &opcao);
        if (opcao == 0) break;

        printf("Quantos dados deseja visualizar? "); // Parte 2 
        scanf("%d", &qtd);

        // Parte 3: Criar o Heap 
        Registro* heap[200]; 
        int tamanho_heap = 0;
        Registro* atual = lista;
        while (atual != NULL && tamanho_heap < 200) {
            heap[tamanho_heap] = atual;
            subir(heap, tamanho_heap, opcao);
            tamanho_heap++;
            atual = atual->prox;
        }

        // Parte 4: Mostrar e "Remover" 
        printf("\n--- RESULTADOS ---\n");
        for (int i = 0; i < qtd && i < tamanho_heap; i++) {
            printf("Pais: %s | Valor: %d\n", heap[i]->pais, 
                   (opcao==1 ? heap[i]->confirmados : (opcao==2 ? heap[i]->mortes : heap[i]->recuperados)));
        }
    } while (opcao != 0);

    return 0;
}