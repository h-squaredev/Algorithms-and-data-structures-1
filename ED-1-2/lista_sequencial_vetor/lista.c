#include "lista.h"

void lista_inicializar(Lista *l){
    l->tamanho = 0;
}

int lista_inserir(Lista *l, int posicao, int valor){
    // verificacoes
    if(lista_cheia(l) == 1){
        printf("Impossível inserir! Lista cheia");
        return 0; // Como a lista esta cheia, a operacao termina aqui
    }
    // A posicao deve ser entre 0 e o tamanho atual para nao deixar espacos vazios
    if(posicao < 0 || posicao > l->tamanho) return 0;

    // Se onde quer adicionar ja esta ocupado
    if(posicao <= l->tamanho){
        // Deslocamento dos elementos pra direita
        for (int i = l->tamanho; i > posicao; i--) {
            l->dados[i] = l->dados[i - 1];
        }
    }

    l->dados[posicao] = valor;
    l->tamanho++;

    return 1; // Deu certo
}


int lista_remover(Lista *l, int posicao, int *valor){
    if(lista_vazia(l) == 1) return 0;

    if(posicao < 0 || posicao > l->tamanho) return 0;

    // Retorna o elemento removido por meio do parâmetro valor
    *valor = l->dados[posicao];

    // Deslocar os elementos posteriores para a esquerda
    for(int i = posicao; i < l->tamanho - 1; i++){
        l->dados[i] = l->dados[i + 1];
    }

    l->tamanho--; // Atualiza o tamanho da lista
    return 1;
}



int lista_buscar(const Lista *l, int valor){
    // Procura o valor e retorna a sua posicao
    for(int i = 0; i < l->tamanho; i++){
        if(l->dados[i] == valor){
            return i; // Retorna o índice encontrado
        }
    }
    return -1; // Retorna um valor que indica que o elemento não foi encontrado
}

void lista_imprimir(const Lista *l){
    for(int i = 0; i < l->tamanho; i++){
        printf("%d ", l->dados[i]);
    }
    printf("\n");
}

int lista_vazia(const Lista *l){
   return(l->tamanho == 0) ? 1 : 0; // Se tamanho for vazio, retorna 1, caso o contrario, retorna 0
}

int lista_cheia(const Lista *l){
    return(l->tamanho == CAPACIDADE) ? 1 : 0;  // Se tamanho igual a CAPACIDADE total do vetor, retorna 1, caso o contrario, retorna 0
}

int lista_tamanho(const Lista *l){
    return l->tamanho; // Apenas retorna o propio tamanho do vetor
}