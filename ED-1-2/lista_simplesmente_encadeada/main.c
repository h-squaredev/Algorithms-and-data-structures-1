#include <stdio.h>
#include "lista.h"

static int total = 0;
static int falhas = 0;

static void verificar(const char *descricao, int condicao){
    total++;
    if(condicao){
        printf("  [OK]    %s\n", descricao);
    } else {
        falhas++;
        printf("  [FALHA] %s\n", descricao);
    }
}

/* Confere estrutura E tamanho: percorre os nos, compara com o vetor esperado,
 * exige que a cadeia termine em NULL com exatamente n nos e que
 * lista_tamanho(l) == n. */
static int confere(const Lista *l, const int *esperado, int n){
    const No *atual = l->inicio;
    int i = 0;

    while(atual != NULL && i < n){
        if(atual->valor != esperado[i]) return 0;
        atual = atual->proximo;
        i++;
    }
    return (i == n && atual == NULL && lista_tamanho(l) == n);
}

int main(void){
    Lista l;
    int removido = 0;

    printf("=== Teste 1: Inicializacao ===\n");
    lista_inicializar(&l);
    lista_imprimir(&l);
    verificar("inicio == NULL", l.inicio == NULL);
    verificar("tamanho == 0", lista_tamanho(&l) == 0);
    verificar("lista vazia", lista_vazia(&l) == 1);

    printf("\n=== Teste 2: Insercao em lista vazia (20) ===\n");
    verificar("insercao com sucesso", lista_inserir(&l, 0, 20) == 1);
    lista_imprimir(&l);
    {
        int esp[] = {20};
        verificar("estrutura e tamanho corretos", confere(&l, esp, 1));
    }
    verificar("lista nao vazia", lista_vazia(&l) == 0);

    printf("\n=== Teste 3: Insercao no inicio (10) ===\n");
    verificar("insercao com sucesso", lista_inserir(&l, 0, 10) == 1);
    lista_imprimir(&l);
    {
        int esp[] = {10, 20};
        verificar("estrutura e tamanho corretos", confere(&l, esp, 2));
    }

    printf("\n=== Teste 4: Insercao no final (40) ===\n");
    verificar("insercao com sucesso", lista_inserir(&l, lista_tamanho(&l), 40) == 1);
    lista_imprimir(&l);
    {
        int esp[] = {10, 20, 40};
        verificar("estrutura e tamanho corretos", confere(&l, esp, 3));
    }

    printf("\n=== Teste 5: Insercao no meio (30 na posicao 2) ===\n");
    verificar("insercao com sucesso", lista_inserir(&l, 2, 30) == 1);
    lista_imprimir(&l);
    {
        int esp[] = {10, 20, 30, 40};
        verificar("estrutura e tamanho corretos", confere(&l, esp, 4));
    }

    printf("\n=== Teste 6: Busca de elemento existente ===\n");
    verificar("buscar 10 -> posicao 0", lista_buscar(&l, 10) == 0);
    verificar("buscar 30 -> posicao 2", lista_buscar(&l, 30) == 2);
    verificar("buscar 40 -> posicao 3", lista_buscar(&l, 40) == 3);

    printf("\n=== Teste 7: Busca de elemento inexistente ===\n");
    verificar("buscar 99 -> -1", lista_buscar(&l, 99) == -1);

    printf("\n=== Teste 8: Remocao no inicio ===\n");
    verificar("remocao com sucesso", lista_remover(&l, 0, &removido) == 1);
    verificar("valor removido == 10", removido == 10);
    lista_imprimir(&l);
    {
        int esp[] = {20, 30, 40};
        verificar("estrutura e tamanho corretos", confere(&l, esp, 3));
    }

    printf("\n=== Teste 9: Remocao no meio ===\n");
    verificar("remocao com sucesso", lista_remover(&l, 1, &removido) == 1);
    verificar("valor removido == 30", removido == 30);
    lista_imprimir(&l);
    {
        int esp[] = {20, 40};
        verificar("estrutura e tamanho corretos", confere(&l, esp, 2));
    }

    printf("\n=== Teste 10: Remocao no final ===\n");
    verificar("remocao com sucesso", lista_remover(&l, lista_tamanho(&l) - 1, &removido) == 1);
    verificar("valor removido == 40", removido == 40);
    lista_imprimir(&l);
    {
        int esp[] = {20};
        verificar("estrutura e tamanho corretos", confere(&l, esp, 1));
    }

    printf("\n=== Teste 11: Remocao ate a lista ficar vazia ===\n");
    verificar("remover ultimo elemento", lista_remover(&l, 0, &removido) == 1);
    verificar("valor removido == 20", removido == 20);
    lista_imprimir(&l);
    verificar("lista vazia", lista_vazia(&l) == 1);
    verificar("inicio == NULL e tamanho == 0", l.inicio == NULL && lista_tamanho(&l) == 0);

    printf("\n=== Teste 12: Operacoes sobre lista vazia ===\n");
    verificar("remover em lista vazia falha", lista_remover(&l, 0, &removido) == 0);
    verificar("buscar em lista vazia retorna -1", lista_buscar(&l, 10) == -1);
    verificar("imprimir lista vazia (apenas NULL)", (lista_imprimir(&l), 1));
    verificar("lista continua consistente", l.inicio == NULL && lista_tamanho(&l) == 0);

    printf("\n=== Teste 13: Posicoes invalidas ===\n");
    {
        int base[] = {10, 20, 30};
        int tam;
        for(int i = 0; i < 3; i++) lista_inserir(&l, i, base[i]);
        tam = lista_tamanho(&l);

        verificar("inserir na posicao -1 falha", lista_inserir(&l, -1, 99) == 0);
        verificar("inserir na posicao tamanho + 1 falha", lista_inserir(&l, tam + 1, 99) == 0);
        verificar("remover na posicao -1 falha", lista_remover(&l, -1, &removido) == 0);
        verificar("remover na posicao tamanho falha", lista_remover(&l, tam, &removido) == 0);
        verificar("remover na posicao tamanho + 1 falha", lista_remover(&l, tam + 1, &removido) == 0);
        verificar("lista nao foi corrompida", confere(&l, base, 3));
    }

    printf("\n=== Teste 14: Destruicao da lista ===\n");
    lista_destruir(&l);
    verificar("inicio == NULL", l.inicio == NULL);
    verificar("tamanho == 0", lista_tamanho(&l) == 0);
    verificar("lista vazia", lista_vazia(&l) == 1);
    lista_destruir(&l); // segunda chamada e segura (nao ha double free)
    verificar("destruir duas vezes nao causa erro", l.inicio == NULL && lista_tamanho(&l) == 0);

    printf("\n=== Resultado: %d/%d verificacoes passaram ===\n", total - falhas, total);
    return falhas == 0 ? 0 : 1;
}

/*
Respostas a Analise das Operacoes

1. Complexidade da busca?
   O(N) no pior caso: e preciso percorrer no a no a partir do inicio, pois
   nao ha acesso direto por indice.

2. Insercao no inicio?
   O(1): so cria o no e ajusta dois ponteiros (novo->proximo e l->inicio),
   sem percorrer nem deslocar nada.

3. Insercao no meio?
   O(N): e preciso percorrer ate o no anterior a posicao (O(N)); o ajuste dos
   ponteiros em si e O(1). Nao ha deslocamento de elementos.

4. Insercao no final?
   O(N), pois a lista guarda apenas o ponteiro para o inicio e precisa
   percorrer todos os nos ate o ultimo. (Seria O(1) se houvesse um ponteiro
   para o fim.)

5. Remocao no inicio?
   O(1): l->inicio passa a apontar para o segundo no e o primeiro e liberado.

6. Remocao no meio?
   O(N): precisa percorrer ate o no anterior ao removido; depois o ajuste
   de ponteiros e O(1).

7. Remocao no final?
   O(N): e preciso chegar ao penultimo no (lista simples nao tem ponteiro
   para o anterior) para tornar seu proximo NULL.

8. Vantagem da lista encadeada sobre o vetor?
   Insercao/remocao no inicio em O(1) e sem deslocar elementos; crescimento
   elemento a elemento sem realloc nem copia de todos os dados e sem
   capacidade maxima; usa memoria proporcional ao numero de elementos.

9. Desvantagem da lista encadeada sobre o vetor?
   Nao ha acesso direto por indice (acessar posicao i e O(N)); cada no gasta
   memoria extra com o ponteiro; os nos ficam espalhados na memoria, com pior
   localidade de cache; e ha mais risco de erros com ponteiros e leaks.

10. Por que malloc() e free() sao necessarios?
    Cada no precisa existir alem do escopo da funcao que o criou, entao e
    alocado dinamicamente no heap com malloc(), e a quantidade de nos so e
    conhecida em tempo de execucao. Como o heap nao e liberado
    automaticamente, cada no deve ser devolvido com free() ao ser removido
    ou quando a lista for destruida; senao ocorre memory leak.
*/
