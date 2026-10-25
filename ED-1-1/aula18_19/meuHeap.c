#include <stdio.h>
#include <stdlib.h>

#define N_HEAP 50

// ESTRUTURA DO HEAP
typedef struct {
    int vetHeap[N_HEAP];
    int count;
} Heap;

// Inicializa o heap
void iniciaHeap(Heap *h){
    h->count = 0;
}

// Funcoes que calculam os indices do heap
int father(int i){
    return (int) (i - 1) / 2;
}

int leftSon(int i){
    return 2 * i + 1;
}

int rightSon(int i){
    return 2 * i + 2;
}

//Funcoes principais do Heap minimo

// sobe o valor até a posição correta (Logica Min-Heap)
void upHeap( Heap *h, int i) {
    int aux;
    if (i > 0) {
        // MIN-HEAP: Se o filho for MENOR que o pai, troca
        if (h->vetHeap[i] < h->vetHeap[indPai(i)]) {
            aux = h->vetHeap[i];
            h->vetHeap[i] = h->vetHeap[indPai(i)];
            h->vetHeap[indPai(i)] = aux;
            
            // Chama recursivamente para continuar subindo
            upHeap(h, indPai(i));
        }
    }
}

// Desce o valor até a posição correta (Logica Min-Heap)
void desceHeap(Heap *h, int i) {
    int ind_menor, aux;
    
    // Verifica se tem filho esquerdo dentro do limite
    if (indFEsq(i) < h->count) {
        ind_menor = indFEsq(i);
        
        // Verifica se tem filho direito e se ele é MENOR que o esquerdo
        if (indFDir(i) < h->count) {
            if (h->vetHeap[indFDir(i)] < h->vetHeap[ind_menor]) {
                ind_menor = indFDir(i);
            }
        }
        
        // MIN-HEAP: Se o filho menor for MENOR que o pai (i), troca
        if (h->vetHeap[ind_menor] < h->vetHeap[i]) {
            aux = h->vetHeap[i];
            h->vetHeap[i] = h->vetHeap[ind_menor];
            h->vetHeap[ind_menor] = aux;
            
            // Chama recursivamente para continuar descendo
            desceHeap(h, ind_menor);
        }
    }
}

// Insere um novo valor no heap
int insereHeap(Heap *h, int valor) {
    if (h->count < N_HEAP) {
        h->vetHeap[h->count] = valor;
        h->count++;
        // Ajusta subindo (heapify up)
        upHeap(h, h->count - 1);
        return 1;
    } else {
        return 0; // Heap cheio
    }
}

// Remove a raiz (que no Min-Heap é o MENOR elemento)
int removeHeap(Heap *h) {
    int valor;
    if (h->count > 0) {
        valor = h->vetHeap[0]; // Pega o menor valor (raiz)
        
        // Pega o último elemento e coloca na raiz
        h->vetHeap[0] = h->vetHeap[--h->count];
        
        // Ajusta descendo (heapify down)
        desceHeap(h, 0);
        return valor;
    }
    return -1; // Heap vazio
}

// Para visualizar
void imprimeHeap(Heap *h) {
    int i;
    printf("Min-Heap (Qtd: %d): [ ", h->count);
    for (i = 0; i < h->count; i++) {
        printf("%d ", h->vetHeap[i]);
    }
    printf("]\n");
}

//Implementacao do Heap Sort usando o Min-Heap
void heapSort(int *vetor, int n) {
    Heap heapAuxiliar;
    inicializaHeap(&heapAuxiliar);
    int i;

    //Construir o Heap (Inserir tudo)
    // Isso organiza os dados segundo a regra do Min-Heap
    for (i = 0; i < n; i++) {
        insereHeap(&heapAuxiliar, vetor[i]);
    }

    // Extraindo ordenado
    // Como é um Min-Heap, o removeHeap sempre devolve o MENOr
    // Preenchemos o vetor original do início ao fim (ordem crescente)
    for (i = 0; i < n; i++) {
        vetor[i] = removeHeap(&heapAuxiliar);
    }
}

// Pequeno teste (opcional, pode remover se for usar outro main)
int main() {
    // Vetor de teste com numeros desordenados
    int myArray[] = {50, 10, 25, 1, 30, 15, 8};
    int size = 7;
    int i;

    printf("--- TESTE DE HEAP SORT (MIN-HEAP) ---\n");
    
    printf("Vetor original: ");
    for(i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    // Executa a ordenacao
    heapSort(myArray, size);

    printf("Vetor ordenado: ");
    for(i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n-------------------------------------\n");

    return 0;