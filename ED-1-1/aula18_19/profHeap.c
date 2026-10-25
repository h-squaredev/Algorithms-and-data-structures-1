// Implementacao do cabeçalho HEAP_H
#include "profHeap.h"

// Funcao que inicializa o heap, inicializando o contador
void inicializaHeap(tipo_heap *hp) {
    hp->contador = 0;
}

// Funcao que calcula o indice do pai de um noh do heap
int indPai(int i) {
    return (int) (i-1)/2;
}

// Funcao que calcula o indice do filho esquerdo de um noh
int indFEsq(int i) {
    return 2*i+1;
}

// Funcao que calcula o indice do filho direito de um noh
int indFDir(int i) {
    return 2*i+2;
}

// Funcao que insere um novo valor no heap
int insereHeap(tipo_heap *hp, int valor) {
    // Verifica se o heap tem espaco
    if (hp->contador < N_HEAP) {
        //Primeira etapa, insere novo valor no final do vetor
        hp->vet_heap[hp->contador] = valor;
        hp->contador++;
        //Segunda etapa, chama funcao de subida do valor
        sobeHeap(hp, hp->contador-1);
        return 1; //sucesso
    } else {
        return 0; //Falha, heap nao tem espaco
    }
}

//Funcao que remove o elemento da raiz
int removeHeap(tipo_heap *hp) {
    int valor;
    if (hp->contador > 0) {
        //Etapa1: guarda valor que estah sendo removido (raiz)
        valor = hp->vet_heap[0];
        //Etapa2: pega o ultimo valor e coloca na raiz
        hp->vet_heap[0] = hp->vet_heap[--hp->contador];
        //Etapa3: Chama a funcao que realiza a descida do valor no heap
        desceHeap(hp, 0);
        return valor;
    }
    return -1; //Erro
}

//Funcao que sobe com o valor ateh sua posicao correta no heap
void sobeHeap(tipo_heap *hp, int i) {
    int aux;
    //Verifica se o indice não eh a raiz
    if (i > 0) {
        if ( hp->vet_heap[i] > hp->vet_heap[ indPai(i) ] ) {
            aux = hp->vet_heap[i];
            hp->vet_heap[i] = hp->vet_heap[indPai(i)];
            hp->vet_heap[indPai(i)] = aux;
            sobeHeap(hp, indPai(i));
        }
    }
}

void desceHeap(tipo_heap *hp, int i){
    int ind_maior, aux;
    //Verifica se o indice do parametro tem filho esquerdo
    if ( indFEsq(i) < hp->contador ) {
        ind_maior = indFEsq(i);
    } 
    //Verifica se tem filho direito
    if ( indFDir(i) < hp->contador ) { 
        //Verifica qual eh o maior entre os filhos
        if (hp->vet_heap[indFDir(i)] > hp->vet_heap[ind_maior])
            ind_maior = indFDir(i);
    }

    //Verifica se o valor do filho maior eh maior que o valor no indice i
    if (hp->vet_heap[ind_maior] > hp->vet_heap[i]) {
        aux = hp->vet_heap[ind_maior];
        hp->vet_heap[ind_maior] = hp->vet_heap[i];
        hp->vet_heap[i] = aux;
    }

    //Chamada recursiva
    desceHeap(hp, ind_maior);
}

//Funcao que imprime o heap - para debugacao
void imprimeHeap(tipo_heap *hp) {
    int i;
    printf("Heap:\nQtd de elementos = %d\n[ ", hp->contador);
    for (i=0; i < hp->contador; i++) {
        printf("%d ", hp->vet_heap[i]);
    }
    printf("]\n");
}
