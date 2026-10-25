#include <stdio.h>
#include <stdlib.h>

// estrutura basica do no
typedef struct No {
    int valor;
    struct No* primeiroFilho;
    struct No* proximoIrmao;
} No;

// cria um no novo na memoria
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->primeiroFilho = NULL;
    novo->proximoIrmao = NULL;
    return novo;
}

// insere um filho em um no pai especifico
void inserir(No* pai, No* filho) {
    if (pai == NULL || filho == NULL) return;

    if (pai->primeiroFilho == NULL) {
        // se nao tem filho ainda, ele e o primeiro
        pai->primeiroFilho = filho;
    } else {
        // se ja tem, vai pro final da lista de irmaos
        No* aux = pai->primeiroFilho;
        while (aux->proximoIrmao != NULL) {
            aux = aux->proximoIrmao;
        }
        aux->proximoIrmao = filho;
    }
}

// pre-ordem: visita a raiz, depois os filhos, depois os irmaos
void preOrdem(No* raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->valor);
    preOrdem(raiz->primeiroFilho);
    preOrdem(raiz->proximoIrmao);
}

// pos-ordem: visita os filhos, a raiz, depois os irmaos
void posOrdem(No* raiz) {
    if (raiz == NULL) return;
    posOrdem(raiz->primeiroFilho);
    printf("%d ", raiz->valor);
    posOrdem(raiz->proximoIrmao);
}

// em-ordem: visita o 1o filho, a raiz, depois o resto dos irmaos
void emOrdem(No* raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->primeiroFilho);
    printf("%d ", raiz->valor);
    emOrdem(raiz->proximoIrmao);
}

// conta nos que nao tem nenhum filho
int contarFolhas(No* raiz) {
    if (raiz == NULL) return 0;
    
    int folhas = 0;
    if (raiz->primeiroFilho == NULL) {
        folhas = 1;
    }
    
    // soma a folha atual (se for) com as folhas dos filhos e dos irmaos
    return folhas + contarFolhas(raiz->primeiroFilho) + contarFolhas(raiz->proximoIrmao);
}

// calcula a altura (considerando numero de nos do maior caminho)
int altura(No* raiz) {
    if (raiz == NULL) return 0;
    
    int altFilho = altura(raiz->primeiroFilho);
    int altIrmao = altura(raiz->proximoIrmao);
    
    // o filho aumenta a profundidade em 1, o irmao ta no mesmo nivel
    if (altFilho + 1 > altIrmao) {
        return altFilho + 1;
    } else {
        return altIrmao;
    }
}

// testando a parada toda
int main() {
    // montando a arvore
    No* raiz = criarNo(1);
    No* f1 = criarNo(2);
    No* f2 = criarNo(3);
    No* f3 = criarNo(4);

    inserir(raiz, f1);
    inserir(raiz, f2);
    inserir(raiz, f3);

    inserir(f1, criarNo(5));
    inserir(f1, criarNo(6));
    
    inserir(f3, criarNo(7));

    printf("Pre-ordem: "); 
    preOrdem(raiz); 
    printf("\n");
    
    printf("Pos-ordem: "); 
    posOrdem(raiz); 
    printf("\n");
    
    printf("Em-ordem:  "); 
    emOrdem(raiz); 
    printf("\n");

    printf("Quantidade de folhas: %d\n", contarFolhas(raiz));
    printf("Altura da arvore: %d\n", altura(raiz));

    return 0;
}