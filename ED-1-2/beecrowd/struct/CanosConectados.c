#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long comprimento;
} Cano;

typedef struct {
    Cano itens[100000];
    int inicio, fim;
} Fila;

Fila a, b;

int comparar(const void *x, const void *y) {
    long long c1 = ((Cano *)x)->comprimento;
    long long c2 = ((Cano *)y)->comprimento;
    return (c1 > c2) - (c1 < c2);
}

/* tira o menor cano entre a frente da fila A e a frente da fila B */
Cano pegarMenor() {
    if (a.inicio == a.fim)
        return b.itens[b.inicio++];
    if (b.inicio == b.fim)
        return a.itens[a.inicio++];
    if (a.itens[a.inicio].comprimento <= b.itens[b.inicio].comprimento)
        return a.itens[a.inicio++];
    return b.itens[b.inicio++];
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%lld", &a.itens[i].comprimento);
    a.inicio = 0;
    a.fim = n;
    b.inicio = b.fim = 0;

    qsort(a.itens, n, sizeof(Cano), comparar);

    long long total = 0;

    /* N canos precisam de N-1 colagens */
    for (int i = 0; i < n - 1; i++) {
        Cano c1 = pegarMenor();
        Cano c2 = pegarMenor();

        Cano novo;
        novo.comprimento = c1.comprimento + c2.comprimento;
        total += novo.comprimento;

        b.itens[b.fim++] = novo;
    }

    printf("%lld\n", total);
    return 0;
}