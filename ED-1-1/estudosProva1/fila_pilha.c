#include <stdio.h>
#include <stdlib.h>

#define TAM 10  // Aumentei um pouco o tamanho para testar tranquilo

// --- ESTRUTURAS DE DADOS ---

// 1. Fila Estática (Vetor)
typedef struct {
    int fila[TAM];
    int inicio, fim;
} Fila;

// 2. Pilha Dinâmica (Encadeada)
// Primeiro definimos o Nó
typedef struct No {
    int dado;
    struct No *prox;
} No;

// Depois definimos a Pilha que segura o topo
typedef struct {
    No *topo;
} Pilha;

// --- FUNÇÕES DE INICIALIZAÇÃO ---

void iniciaFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

void iniciaPilha(Pilha *p) {
    p->topo = NULL;
}

// --- FUNÇÕES DA FILA (Enfileirar / Desenfileirar) ---

void enfileirar(Fila *f, int valor) {
    if (f->fim < TAM) {
        f->fila[f->fim] = valor;
        f->fim++;
    } else {
        printf("Fila cheia!\n");
    }
}

int desenfileirar(Fila *f) {
    if (f->inicio != f->fim) {
        int aux = f->fila[f->inicio];
        f->inicio++;
        return aux;
    } else {
        printf("Fila Vazia!\n");
        return -1; // Retorna erro
    }
}

// --- FUNÇÕES DA PILHA (Empilhar / Desempilhar) ---

void empilhar(Pilha *p, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = p->topo; // Conecta no antigo topo
    p->topo = novo;       // Atualiza o topo
}

int desempilhar(Pilha *p) {
    if (p->topo == NULL) {
        printf("Pilha Vazia!\n");
        return -1;
    } else {
        No *aux = p->topo;      // Salva o topo atual
        int valor = aux->dado;  // Salva o valor
        p->topo = aux->prox;    // Move o topo para baixo
        free(aux);              // Libera a memória
        return valor;
    }
}

// --- A ESTRELA DA PROVA: INVERTER A FILA ---

void inverteFila(Fila *f) {
    Pilha p;
    iniciaPilha(&p);

    // Passo 1: Tira da Fila -> Põe na Pilha
    printf("Transferindo da Fila para a Pilha...\n");
    while (f->inicio != f->fim) {
        int val = desenfileirar(f);
        empilhar(&p, val);
    }

    // Passo 2: Tira da Pilha -> Põe na Fila
    printf("Devolvendo da Pilha para a Fila...\n");
    while (p.topo != NULL) {
        int val = desempilhar(&p);
        enfileirar(f, val);
    }
}

// --- FUNÇÃO AUXILIAR PARA IMPRIMIR A FILA (Só para vermos o resultado) ---
void imprimeFila(Fila *f) {
    printf("Fila Atual: [ ");
    for (int i = f->inicio; i < f->fim; i++) {
        printf("%d ", f->fila[i]);
    }
    printf("]\n");
}

// --- MAIN (Onde a mágica acontece) ---

int main() {
    Fila minhaFila;
    
    // 1. Preparar a fila
    iniciaFila(&minhaFila);
    
    // 2. Colocar dados: 10, 20, 30
    printf("--- ENCHENDO A FILA ---\n");
    enfileirar(&minhaFila, 10);
    enfileirar(&minhaFila, 20);
    enfileirar(&minhaFila, 30);
    
    imprimeFila(&minhaFila); // Esperado: [ 10 20 30 ]
    
    // 3. Inverter!
    printf("\n--- INVERTENDO ---\n");
    inverteFila(&minhaFila);
    
    // 4. Conferir o resultado
    printf("\n--- RESULTADO FINAL ---\n");
    imprimeFila(&minhaFila); // Esperado: [ 30 20 10 ]

    return 0;
}